/* 
 * File:   main.cpp
 * Author: Vladislav Kupiryn
 *         Anton Fedotov
 *         Daniil Razuvaev
 *
 * Created on 14 Ноябрь 2015 г., 16:47
 */

#include <qt5/QtWidgets/QApplication>
#include <omp.h>

#include "gui/gui.h"
#include "pos_system/pos_sys.h"
#include "connecter/connector.h"
#include "settings/settings.h"

int main( int argc, char** argv )
{
   QApplication app(argc, argv);
   
   connector_t connector;
   
   gui_t window(&connector);

   window.show();  
   window.setStartSize();

   pos_system_t track(&connector);
   
   size_t thread_idx;
   
   omp_set_num_threads(2);
   
   #pragma omp parallel private(thread_idx)
   {
      thread_idx = omp_get_thread_num();
      
      cout << thread_idx << endl;
      
      if (thread_idx == 0)
         app.exec();
      
      if (thread_idx == 1)
         track.loop();
   }
   
   return 0;
}   


