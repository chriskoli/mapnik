/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2012 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/
//mapnik
#include <mapnik/text/placement_finder_ng.hpp>
#include <mapnik/text/layout.hpp>
#include <mapnik/text_properties.hpp>

//boost
#include <boost/make_shared.hpp>

namespace mapnik
{

placement_finder_ng::placement_finder_ng( Feature const& feature, DetectorType &detector, box2d<double> const& extent)
    : feature_(feature), detector_(detector), extent_(extent)
{
}

glyph_positions_ptr placement_finder_ng::find_point_placement(text_layout_ptr layout, double pos_x, double pos_y)
{
    glyph_positions_ptr glyphs = boost::make_shared<glyph_positions>();
//    glyphs->point_placement(pixel_position(pos_x, pos_y));
    //TODO: angle
    //TODO: Check for placement
    return glyphs;
}

glyph_positions::glyph_positions()
    : base_point_(), const_angle_(true)
{

}

glyph_positions::const_iterator glyph_positions::begin() const
{
    return data_.begin();
}

glyph_positions::const_iterator glyph_positions::end() const
{
    return data_.end();
}

void glyph_positions::push_back(const glyph_info &glyph, pixel_position offset, double angle)
{
    if (data_.empty())
    {
        angle_ = angle;
    } else
    {
        if (angle != angle_) const_angle_ = false;
    }
    data_.push_back(glyph_position(glyph, offset, angle));
}


bool glyph_positions::is_constant_angle() const
{
    return const_angle_;
}

double glyph_positions::get_angle() const
{
    return angle_;
}

const pixel_position &glyph_positions::get_base_point() const
{
    return base_point_;
}


}// ns mapnik