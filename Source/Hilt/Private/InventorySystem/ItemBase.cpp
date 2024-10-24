// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/ItemBase.h"

FSlotStruct::FSlotStruct()
{
}

FSlotStruct::FSlotStruct(const int quantity, UItemBase* item) : Item(item), Quantity(quantity)
{
}

FSlotStruct::FSlotStruct(UItemBase* item) : Item(item), Quantity(1)
{
}

//bool FSlotStruct::TransferContentsTo(FSlotStruct& Destination)
//{
//	//we have valid data to send
//	if (this->Quantity <= 0 || this->Item == nullptr)
//	{
//		return false;
//	}
//
//	//make destination hold our item if it has no item
//	if (Destination.Item == nullptr || Destination.Quantity == 0)
//	{
//		Destination = *this;
//		*this = nullptr;
//	}
//
//	//abort if destination has its own item
//	else if (Destination.Item != this->Item)
//	{
//		return false;
//	}
//
//	//abort if destination has no extra capacity
//	else if (Destination.Quantity >= Destination.Item->MaxQuantity)
//	{
//		return false;
//	}
//
//	const int AvailableCapacity = Destination.Item->MaxQuantity - Destination.Quantity;
//
//	for (int i = 0; i < AvailableCapacity; ++i)
//	{
//		if (this->Quantity > 0 && Destination.Quantity <= Destination.Item->MaxQuantity)
//		{
//			this->Quantity--;
//			Destination.Quantity++;
//			if (this->Quantity == 0)
//			{
//				*this = nullptr;
//				return true;
//			}
//		}
//	}
//	return false;
//}

void FSlotStruct::operator=(FSlotStruct ToBe)
{
	this->Quantity = ToBe.Quantity;
	this->Item = ToBe.Item;
}

void FSlotStruct::operator=(nullptr_t Nullptr)
{
	this->Item = nullptr;
	this->Quantity = 0;
}


FSlotStruct::operator bool() const
{
	if (this->Item != nullptr && this->Quantity > 0)
	{
		return true;
	}
	return false;
}

bool operator==(const FSlotStruct& lhs, const FSlotStruct& rhs)
{
	return lhs.Item == rhs.Item && lhs.Quantity == rhs.Quantity;
}
