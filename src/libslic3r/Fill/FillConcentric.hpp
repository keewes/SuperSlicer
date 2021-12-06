#ifndef slic3r_FillConcentric_hpp_
#define slic3r_FillConcentric_hpp_

#include "FillBase.hpp"

namespace Slic3r {

class FillConcentric : public Fill
{
public:
    ~FillConcentric() override = default;

protected:
    Fill* clone() const override { return new FillConcentric(*this); };
    void init_spacing(double spacing, const FillParams &params) override;
    void _fill_surface_single(
        const FillParams                &params,
        unsigned int                     thickness_layers,
        const std::pair<float, Point>   &direction,
        ExPolygon                        expolygon,
        Polylines                       &polylines_out) const override;

	bool no_sort() const override { return true; }
};


class FillConcentricWGapFill : public Fill {
public:
    virtual ~FillConcentricWGapFill() {}

protected:
    Fill* clone() const override { return new FillConcentricWGapFill(*this); };
    void fill_surface_extrusion(const Surface *surface, const FillParams &params, ExtrusionEntitiesPtr &out) const override;

    bool no_sort() const override { return true; }
};

} // namespace Slic3r

#endif // slic3r_FillConcentric_hpp_
