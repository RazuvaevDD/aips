/* 
 * File:   connecter.h
 * Author: Razuvaev Daniil
 *         Kupirin Vladislav
 *
 * Created on 28 ноября 2015 г., 17:06
 */

#pragma once 

#include <QObject>
#include <QImage>

class connector_t : public QObject
{
   Q_OBJECT

public:
   connector_t( );

   void stop_obj_track();

   // slots

   Q_SLOT void export_settings_slt();
   
   Q_SLOT void import_settings_slt();
   
   Q_SLOT void get_image( QImage image );
   
   Q_SLOT void set_brightness_hardware_slt( double hbrightness );
   Q_SLOT void set_contrast_hardware_slt( double hcontrast );
   Q_SLOT void set_saturation_hardware( double hsaturation );
   Q_SLOT void set_hue_hardware( double hhue );
   Q_SLOT void set_gain_hardware( double hgain );
   Q_SLOT void set_exposure_hardware( double hexposure );

   Q_SLOT void set_brightness_software( double sbrightness );
   Q_SLOT void set_contrast_software( double scontrast );

   Q_SLOT void set_min_h( int min_h );
   Q_SLOT void set_max_h( int max_h );
   Q_SLOT void set_min_s( int min_s );
   Q_SLOT void set_max_s( int max_s );
   Q_SLOT void set_min_v( int min_v );
   Q_SLOT void set_max_v( int max_v );
   Q_SLOT void set_min_size( int min_size );
   Q_SLOT void set_max_size( int max_size );
   
   Q_SLOT void get_min_h( int min_h );
   Q_SLOT void get_max_h( int max_h );
   Q_SLOT void get_min_s( int min_s );
   Q_SLOT void get_max_s( int max_s );
   Q_SLOT void get_min_v( int min_v );
   Q_SLOT void get_max_v( int max_v );
   Q_SLOT void get_min_size( int min_size );
   Q_SLOT void get_max_size( int max_size );
  
   //////////////////////////////////
   Q_SLOT void get_brightness_h_slt(double brightness_h);
   Q_SLOT void get_hue_h_slt(double hue_h);
   Q_SLOT void get_contrast_h_slt(double contrast_h);
   Q_SLOT void get_gain_h_slt(double gain_h);
   Q_SLOT void get_exposure_h_slt(double exposure_h);
   Q_SLOT void get_saturation_h_slt(double saturation_h);
   
   Q_SLOT void get_brightness_s_slt(double brightness_s);
   Q_SLOT void get_contrast_s_slt(double contrast_s);
   
           // signals
   
   Q_SIGNAL void get_brightness_h(double);
   Q_SIGNAL void get_hue_h(double);
   Q_SIGNAL void get_contrast_h(double);
   Q_SIGNAL void get_gain_h(double);
   Q_SIGNAL void get_exposure_h(double);
   Q_SIGNAL void get_saturation_h(double);
   
   Q_SIGNAL void get_brightness_s(double);
   Q_SIGNAL void get_contrast_s(double);
   

   Q_SIGNAL void send_image( QImage image );
   Q_SIGNAL void stop_obj_track_s();
   
   Q_SIGNAL void export_settings_s();
   Q_SIGNAL void import_settings_s();
   
   Q_SIGNAL void set_brightness_hardware_sig( double value );
   Q_SIGNAL void set_contrast_hardware_sig( double value );
   Q_SIGNAL void set_hue_hardware_sig( double value );
   Q_SIGNAL void set_saturation_hardware_sig( double value );
   Q_SIGNAL void set_gain_hardware_sig( double value );
   Q_SIGNAL void set_exposure_hardware_sig( double value );
   
   Q_SIGNAL void set_min_h_sig( int min_h );
   Q_SIGNAL void set_max_h_sig( int max_h );
   Q_SIGNAL void set_min_s_sig( int min_s );
   Q_SIGNAL void set_max_s_sig( int max_s );
   Q_SIGNAL void set_min_v_sig( int min_v );
   Q_SIGNAL void set_max_v_sig( int max_v );
   Q_SIGNAL void set_min_size_sig( int min_size );
   Q_SIGNAL void set_max_size_sig( int max_size );
   
   Q_SIGNAL void get_min_h_sig( int min_h );
   Q_SIGNAL void get_max_h_sig( int max_h );
   Q_SIGNAL void get_min_s_sig( int min_s );
   Q_SIGNAL void get_max_s_sig( int max_s );
   Q_SIGNAL void get_min_v_sig( int min_v );
   Q_SIGNAL void get_max_v_sig( int max_v );
   Q_SIGNAL void get_min_size_sig( int min_size );
   Q_SIGNAL void get_max_size_sig( int max_size );
   
   Q_SIGNAL void set_brightness_software_sig( double sbrightness );
   Q_SIGNAL void set_contrast_software_sig( double scontrast );
   
   Q_SIGNAL void brightness_h_sig(double brightness_h);
   Q_SIGNAL void hue_h_sig(double hue_h);
   Q_SIGNAL void contrast_h_sig(double contrast_h);
   Q_SIGNAL void gain_h_sig(double gain_h);
   Q_SIGNAL void exposure_h_sig(double exposure_h);
   Q_SIGNAL void saturation_h_sig(double saturation_h);
   
   
   Q_SIGNAL void brightness_s_sig(double brightness_s); 
   Q_SIGNAL void contrast_s_sig(double contrast_s);

private:
};