/* This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
 * Copyright (c) 2026 Klumzy Duk Gamez
 * See LICENSE.md for license details */

#if !defined __KLUMZY_MEMORY_H__
#define __KLUMZY_MEMORY_H__

#include "Klumzy_Common.h"

#if defined __cplusplus
extern "C" {
#endif /* if defined __cplusplus */

KLUMZY_DLL Klumzy_Result Klumzy_AllocateRawMemory(Klumzy_UInt size, Klumzy_Void** memory);
KLUMZY_DLL Klumzy_Result Klumzy_FreeRawMemory(Klumzy_UInt size, Klumzy_Void** memory);

typedef struct {
	Klumzy_Void* address;
	Klumzy_UInt size;
} Klumzy_MemoryRegion;

typedef struct {
	Klumzy_MemoryRegion region;
	Klumzy_MemoryRegion top;
} Klumzy_StackMemoryAllocator;

KLUMZY_DLL Klumzy_Result Klumzy_SetupStackMemoryAllocator(Klumzy_Void* address, Klumzy_UInt size, Klumzy_StackMemoryAllocator* allocator);
KLUMZY_DLL Klumzy_Result Klumzy_DestroyStackMemoryAllocator(Klumzy_StackMemoryAllocator* allocator);
KLUMZY_DLL Klumzy_Result Klumzy_AllocateMemoryFromStackAllocator(Klumzy_StackMemoryAllocator* allocator, Klumzy_UInt size, Klumzy_MemoryRegion* region);
KLUMZY_DLL Klumzy_Result Klumzy_FreeMemoryFromStackAllocator(Klumzy_StackMemoryAllocator* allocator, Klumzy_MemoryRegion* region);

#if defined __cplusplus
} /* extern "C" */
#endif /* if defined __cplusplus */

#endif /* if !defined __KLUMZY_MEMORY_H__ */
