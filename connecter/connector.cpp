#include <iostream>

#include "connector.h"
#include "../camera/camera.h"

using namespace std;

connector_t::connector_t()
{
}

void connector_t::stop_obj_track()
{
   emit stop_obj_track_s();
}


Q_SLOT void connector_t::get_image( QImage image )
{
   emit send_image(image);
}


Q_SLOT void connector_t::set_brightness_hardware_slt( double value )
{
   emit set_brightness_hardware_sig( value );
}

Q_SLOT void connector_t::set_contrast_hardware_slt( double value )
{
   emit set_contrast_hardware_sig( value );
}


Q_SLOT void connector_t::set_saturation_hardware( double value )
{
   emit set_saturation_hardware_sig( value );
}

Q_SLOT void connector_t::set_hue_hardware( double value )
{
   emit set_hue_hardware_sig( value );
}

Q_SLOT void connector_t::set_gain_hardware( double value )
{
   emit set_gain_hardware_sig( value );
}

Q_SLOT void connector_t::set_exposure_hardware( double value )
{
   emit set_exposure_hardware_sig( value );
}

Q_SLOT void connector_t::set_brightness_software( double value )
{
   emit set_brightness_software_sig( value );
}

Q_SLOT void connector_t::set_contrast_software(double value )
{
   emit set_contrast_software_sig( value );
}

Q_SLOT void connector_t::set_min_h(int min_h)
{
   emit set_min_h_sig( min_h );
}

Q_SLOT void connector_t::set_max_h(int max_h)
{
   emit set_max_h_sig( max_h );   
}

Q_SLOT void connector_t::set_min_s(int min_s)
{
   emit set_min_s_sig( min_s );   
}

Q_SLOT void connector_t::set_max_s(int max_s)
{
   emit set_max_s_sig( max_s );   
}

Q_SLOT void connector_t::set_min_v(int min_v)
{
   emit set_min_v_sig( min_v );   
}

Q_SLOT void connector_t::set_max_v(int max_v)
{
   emit set_max_v_sig( max_v );   
}

Q_SLOT void connector_t::set_min_size(int min_size)
{
   emit set_min_size_sig( min_size );   
}

Q_SLOT void connector_t::set_max_size(int max_size)
{
   emit set_max_size_sig( max_size );   
}