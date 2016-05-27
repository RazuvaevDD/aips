/* 
 * File:   gui.h
 * Author: Daniil Razuvaev
 *         Anton Fedotov
 * Created on 14 ноября 2015 г., 20:17
 */

#pragma once 

#include <QMainWindow>
#include <QApplication>
#include <QObject>
#include <QMenu>
#include <QTimer>
#include <QMenuBar>
#include <QMouseEvent>

#include "ui/gui_ui.h"
#include "ui/object_params_ui.h"
#include "ui/camera_settings_ui.h"
#include "ui/calibration_coordinates_ui.h"
#include "../connecter/connector.h"

namespace Ui
{
   class gui;
   class obj_params;
   class camera_settings;
   class calibration_coordinates;
   class VideoLayout;
}

class object_params_t;
class camera_settings_t;
class calibration_coordinates_t;
class VideoLayout_t;

class gui_t : public QMainWindow
{
   Q_OBJECT
   
/////////////////////MENU/////////////////////////////
private slots:                                      //
   void contextMenuRequested(const QPoint& point);  //
   void setMarker1();                               //
   void setMarker2();                               //
   void setMarker3();                               //
   //void setMarker0();                             //
                                                    //
    private:                                        //
      QMenu*   m_pContextMenu;                      //
      QAction* m_pAction1;                          //
      QAction* m_pAction2;                          //
      QAction* m_pAction3;                          //
      QAction* m_pAction4;                          //
//////////////////////////////////////////////////////
public:
   gui_t ( connector_t * connector, QWidget * parent = 0 );
   void resizeEvent(QResizeEvent*);
   void setStartSize();
   void closeEvent(QCloseEvent * event);
   void mousePressEvent(QMouseEvent * event);
   
   double SizeProportion;
   double SizeProportionCoordinates;
   QSize SizeImage;
   QPoint ClickPos;

   const int START_WINDOW_SIZE = 650;
   
private:
   int StartSize;
   int StopSetStartSize;
   Q_SLOT void call_obj_params();
   Q_SLOT void call_camera_settings();
   Q_SLOT void call_calibration_coordinates();
   
   Q_SLOT void redraw_image(QImage image);
   
   Q_SLOT void export_settings_slt();
   
   Q_SLOT void import_settings_slt();
   
   Q_SIGNAL void export_settings_sig2();
   
   Q_SIGNAL void import_settings_sig();
   
   
   
   Ui::gui * ui_;

   object_params_t *   object_params_;
   camera_settings_t * camera_settings_;
   calibration_coordinates_t * calibration_coordinates_;
   connector_t * connector_;
   VideoLayout_t * VideoLayout_;
};


class object_params_t : public QMainWindow
{
   Q_OBJECT

public:
   object_params_t(connector_t * connector, QWidget * parent = 0 );
   
   Q_SLOT void set_min_h_q_slt_ot_g(int);
   Q_SLOT void set_max_h_q_slt_ot_g(int);
   Q_SLOT void set_min_s_q_slt_ot_g(int);
   Q_SLOT void set_max_s_q_slt_ot_g(int);
   Q_SLOT void set_min_v_q_slt_ot_g(int);
   Q_SLOT void set_max_v_q_slt_ot_g(int);
   Q_SLOT void set_min_size_q_slt_ot_g(int);
   Q_SLOT void set_max_size_q_slt_ot_g(int);

private:
   Ui::obj_params * obj_params_;
   connector_t *    connector_;
};

class camera_settings_t : public QMainWindow
{
   Q_OBJECT

public:
   camera_settings_t( connector_t * connector, QWidget * parent = 0 );
   
   Q_SLOT void set_brightness_h_slt (double);
   Q_SLOT void set_hue_h_slt        (double);
   Q_SLOT void set_contrast_h_slt   (double);
   Q_SLOT void set_gain_h_slt       (double);
   Q_SLOT void set_exposure_h_slt   (double);
   Q_SLOT void set_saturation_h_slt (double);
    
   Q_SLOT void set_brightness_s_slt (double);
   Q_SLOT void set_contrast_s_slt   (double);
  
private:
   Ui::camera_settings * camera_settings_;
   
   connector_t * connector_;
   
};

class calibration_coordinates_t : public QMainWindow
{
   Q_OBJECT
public:
   calibration_coordinates_t ( connector_t * connector, QWidget * parent = 0 );
   QPoint Marker1_CamCoordinates;
   QPoint Marker2_CamCoordinates;
   QPoint Marker3_CamCoordinates;
   
   void set_Marker1(int x, int y);
   void set_Marker2(int x, int y);
   void set_Marker3(int x, int y);
   bool Marker_Set(int x, int y);
private:
   Ui::gui * ui_;
   Ui::calibration_coordinates * calibration_coordinates_;
};

class VideoLayout_t : public QLabel
{
public:
   VideoLayout_t();
   QPoint ClickPos;
   QPoint getClickPos();
private:
   void mousePressEvent(QMouseEvent * event);
};