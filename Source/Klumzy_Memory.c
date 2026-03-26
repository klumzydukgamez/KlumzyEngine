/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#include "Klumzy_Memory.h"

Klumzy_Result Klumzy_SetupStackMemoryAllocator(Klumzy_Void* address, Klumzy_UInt size, Klumzy_StackMemoryAllocator* allocator) {
	if (allocator->region.size != 0) {
		return Klumzy_Result_ERROR_UNKNOWN;
	}

	allocator->region.address = address;
	allocator->region.size = size;

	allocator->top.address = allocator->region.address;
	allocator->top.size = 0;

	return Klumzy_Result_SUCCESS;
}

Klumzy_Result Klumzy_DestroyStackMemoryAllocator(Klumzy_StackMemoryAllocator* allocator) {
	if (allocator->region.size == 0) {
		return Klumzy_Result_ERROR_UNKNOWN;
	}

	allocator->region.address = Klumzy_Null;
	allocator->region.size = 0;

	allocator->top = allocator->region;

	return Klumzy_Result_SUCCESS;
}

Klumzy_Result Klumzy_AllocateMemoryFromStackAllocator(Klumzy_StackMemoryAllocator* allocator, Klumzy_UInt size, Klumzy_MemoryRegion* region) {
	if (allocator->region.size == 0) {
		return Klumzy_Result_ERROR_UNKNOWN;
	}

	if (allocator->top.size == allocator->region.size) {
		return Klumzy_Result_ERROR_UNKNOWN;
	}

	if (size > allocator->region.size - allocator->top.size) {
		size = allocator->region.size - allocator->top.size;
	}

	region->address = allocator->top.address;
	region->size = size;

	allocator->top.address = (Klumzy_Void*)((Klumzy_Int8*)allocator->top.address + size);
	allocator->top.size += size;

	return Klumzy_Result_SUCCESS;
}

Klumzy_Result Klumzy_FreeMemoryFromStackAllocator(Klumzy_StackMemoryAllocator* allocator, Klumzy_MemoryRegion* region) {
	if (allocator->region.size == 0) {
		return Klumzy_Result_ERROR_UNKNOWN;
	}

	if (allocator->top.size <= 0) {
		return Klumzy_Result_ERROR_UNKNOWN;
	}

	Klumzy_UInt size = region->size;
	if (size > allocator->top.size) {
		size = allocator->top.size;
	}

	region->address = Klumzy_Null;
	region->size = 0;

	allocator->top.address = (Klumzy_Void*)((Klumzy_Int8*)allocator->top.address - size);
	allocator->top.size -= size;

	return Klumzy_Result_SUCCESS;
}
