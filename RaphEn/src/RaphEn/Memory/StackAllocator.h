#pragma once

#include "RaphEn/Memory/MemoryAllocator.h"

namespace raphen::memory {

	// lorem boilerplate
	// maybe internal block objects to keep track of allocated data to help freeing/defraging (play around with it)
	class StackAllocator : public MemoryAllocator
	{
	public:

		// Allocates a big block on the heap on construction
		// @param stack_size: size of the memory the Stack Allocator manages in bytes
		explicit StackAllocator(size_t stack_size);

		// No Copy or move constructors, or assignement
		StackAllocator(const StackAllocator&) = delete;
		StackAllocator(StackAllocator&&) = delete;
		StackAllocator& operator = (const StackAllocator&) = delete;

		// Allocate bloack of memory in StackAllocator managed memory
		// @param size: size in bytes of memory block
		// @return pointer to memory block, or nullptr if couldn't allocate
		void* allocate(size_t size);

		void roll_back();

	protected:
		void* m_buffer;
		size_t m_buffer_size;
		size_t m_max_buffer_size;
	};
}