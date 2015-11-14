TARGET = aips

GUI_DIR       = gui
OBJ_TRACK_DIR = object_track
BIN_DIR       = bin
OBJ_DIR       = obj

CPP_SRC = $(OBJ_TRACK_DIR)/object_track.cpp main.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(CPP_SRC:.cpp=.o)))
	
CPP_INCLUDE_FILES = -I/usr/local/include/opencv -I/usr/local/include -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore
CPP_LIBS = -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal -L/usr/lib/x86_64-linux-gnu -lQtCore -lQtGui
CPP_FLG = -std=c++11

all: dir $(TARGET)
	
dir: 
	if !(test -d $(BIN_DIR)); then mkdir $(BIN_DIR); fi
	if !(test -d $(OBJ_DIR)); then mkdir $(OBJ_DIR); fi

aips: $(OBJ_FILES)
	g++ -g $(OBJ_FILES) -o $(BIN_DIR)/$(TARGET) $(CPP_LIBS)
	
$(OBJ_DIR)/%.o: %.cpp
	g++ -g -c $< -o $@ $(CPP_FLG) $(CPP_INCLUDE_FILES)

$(OBJ_DIR)/%.o: $(OBJ_TRACK_DIR)/%.cpp
	g++ -g -c $< -o $@ $(CPP_FLG) $(CPP_INCLUDE_FILES)
	
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)