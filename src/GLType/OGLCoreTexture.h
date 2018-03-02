#pragma once

#include <GL/glew.h>
#include <string>
#include <GraphicsTypes.h>
#include <tools/Rtti.h>
#include <GLType/GraphicsTexture.h>

class OGLCoreTexture final : public GraphicsTexture
{
	__DeclareSubInterface(OGLCoreTexture, GraphicsTexture)
public:

	OGLCoreTexture();
    virtual ~OGLCoreTexture();

    static OGLCoreTexturePtr Create(GLint width, GLint height, GLenum target, GLenum format, GLuint levels);
    static OGLCoreTexturePtr Create(const std::string& filename);

    bool create(const GraphicsTextureDesc& desc);
	bool create(const std::string& filename);
	bool create(GLint width, GLint height, GLenum target, GLenum format, GLuint levels);
	void destroy();
	void bind(GLuint unit) const;
	void unbind(GLuint unit) const;
	void generateMipmap();
	void parameter(GLenum pname, GLint param);

    bool createFromFileGLI(const std::string& filename);
    bool createFromFileSTB(const std::string& filename);

    GLuint getTextureID() const noexcept;

    const GraphicsTextureDesc& getGraphicsTextureDesc() const noexcept;

private:

	friend class OGLDevice;
	void setDevice(const GraphicsDevicePtr& device) noexcept;
	GraphicsDevicePtr getDevice() noexcept;

private:

	OGLCoreTexture(const OGLCoreTexture&) noexcept = delete;
	OGLCoreTexture& operator=(const OGLCoreTexture&) noexcept = delete;

// private:
public:

    GraphicsTextureDesc m_TextureDesc;

	GLuint m_TextureID;
	GLenum m_Target;
	GLenum m_Format;
	GLint m_Width;
	GLint m_Height;
	GLint m_Depth;
	GLint m_MipCount;
	GraphicsDeviceWeakPtr m_Device;
};

