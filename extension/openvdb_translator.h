#pragma once

#include <translators/shape/ShapeTranslator.h>
#include <utils/Version.h>

#include "shader_translator.h"

class OpenvdbTranslator : public VDBShaderParamsTranslator<CShapeTranslator> {
public:
    static void* creator();

    virtual AtNode* CreateArnoldNodes();

    virtual void Export(AtNode* volume) override;

#if MTOA_ARCH_VERSION_NUM == 1 && MTOA_MAJOR_VERSION_NUM <= 3
    virtual void ExportMotion(AtNode* volume, unsigned int step) override;
#else
    virtual void ExportMotion(AtNode* volume) override;
#endif

};
