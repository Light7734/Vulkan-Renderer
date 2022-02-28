#pragma once

#include "Core/Base.hpp"

#include <volk.h>

struct BufferCreateInfo
{
	VkDevice logicalDevice;
	VkPhysicalDevice physicalDevice;
	VkCommandPool commandPool;
	VkQueue graphicsQueue;
	VkBufferUsageFlags usage;
	VkDeviceSize size;
	void* startingData = nullptr;
};

class Buffer
{
public:
	Buffer(BufferCreateInfo& createInfo);
	~Buffer();

	inline VkBuffer* GetBuffer() { return &m_Buffer; }

private:
	VkDevice m_LogicalDevice;

	VkBuffer m_Buffer;
	VkDeviceMemory m_BufferMemory;

	VkBuffer m_StagingBuffer;
	VkDeviceMemory m_StagingBufferMemory;
};
