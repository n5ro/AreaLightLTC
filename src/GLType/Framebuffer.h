#pragma once

#include <GraphicsTypes.h>

class AttachmentBinding final
{
public:

    AttachmentBinding(const OGLCoreTexturePtr& texture, std::uint32_t attachment, std::uint32_t mipLevel = 0, std::uint32_t layer = 0) noexcept;
    ~AttachmentBinding() noexcept;

    OGLCoreTexturePtr m_Texture;
    std::uint32_t m_Attachment;
    std::uint32_t m_MipLevel;
    std::uint32_t m_Layer;
};

class FramebufferDesc final
{
public:

    FramebufferDesc() noexcept;
    ~FramebufferDesc() noexcept;

	void addComponent(const AttachmentBinding& component) noexcept;
	const AttachmentBindings& getComponents() const noexcept;

private:

	AttachmentBindings m_Bindings;
};

class GraphicsFramebuffer final
{
public:

    static FramebufferPtr Create(const FramebufferDesc& desc) noexcept;

    GraphicsFramebuffer() noexcept;
    ~GraphicsFramebuffer() noexcept;

    void bind() noexcept;
    bool create(const FramebufferDesc& desc);
	void destroy() noexcept;

private:

    std::uint32_t m_FBO;
    FramebufferDesc m_FramebufferDesc;
};
