#pragma once

#include "Define.h"

NS_CC_BEGIN

class GFXDevice;

NS_CC_END

NS_PP_BEGIN

class RenderPipeline;
class RenderStage;
class RenderView;

class CC_DLL RenderFlow : public cocos2d::Object {
public:
    RenderFlow() = default;
    virtual ~RenderFlow() = default;

    virtual bool initialize(const RenderFlowInfo &info);
    virtual void activate(RenderPipeline *pipeline);
    virtual void resize(uint width, uint height);
    virtual void render(RenderView *view);

    virtual void destroy() = 0;
    virtual void rebuild() = 0;

    void destroyStages();

    CC_INLINE const cocos2d::GFXDevice *getDevice() const { return _device; }
    CC_INLINE const RenderPipeline *getPipeline() const { return _pipeline; }
    CC_INLINE const cocos2d::String &getName() const { return _name; }
    CC_INLINE int getPriority() const { return _priority; }
    CC_INLINE const RenderStageList &getStages() const { return _stages; }
    //    CC_INLINE const Material *getMaterial() const { return _material; }
    //    CC_INLINE RenderFlowType getType() const { return _type; }

protected:
    void activateStages();

protected:
    cocos2d::GFXDevice *_device = nullptr;
    RenderPipeline *_pipeline = nullptr;
    cocos2d::String _name;
    int _priority = 0;
    RenderStageList _stages;
    //    Material *_material = nullptr;
    //    RenderFlowType _type = ;
};

NS_PP_END