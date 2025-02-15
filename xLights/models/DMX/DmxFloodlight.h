#pragma once

/***************************************************************
 * This source files comes from the xLights project
 * https://www.xlights.org
 * https://github.com/smeighan/xLights
 * See the github commit history for a record of contributing
 * developers.
 * Copyright claimed based on commit dates recorded in Github
 * License: https://github.com/smeighan/xLights/blob/master/License.txt
 **************************************************************/

#include "DmxModel.h"
#include "DmxColorAbility.h"
#include "DmxShutterAbility.h"

class DmxFloodlight : public DmxModel, public DmxColorAbility, public DmxShutterAbility
{
    public:
        DmxFloodlight(wxXmlNode *node, const ModelManager &manager, bool zeroBased = false);
        virtual ~DmxFloodlight();

    protected:
        virtual void InitModel() override;

        virtual void ExportXlightsModel() override;
        virtual void ImportXlightsModel(std::string const& filename, xLightsFrame* xlights, float& min_x, float& max_x, float& min_y, float& max_y) override;

        virtual bool HasColorAbility() override { return true; }

        virtual void AddTypeProperties(wxPropertyGridInterface* grid) override;
        virtual void DisableUnusedProperties(wxPropertyGridInterface* grid) override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface* grid, wxPropertyGridEvent& event) override;

        virtual void DrawModelOnWindow(ModelPreview* preview, DrawGLUtils::xlAccumulator &va, const xlColor *c, float &sx, float &sy, bool active) override;
        virtual void DrawModelOnWindow(ModelPreview* preview, DrawGLUtils::xl3Accumulator &va, const xlColor *c, float &sx, float &sy, float &sz, bool active) override;

        float beam_length;

    private:
};
