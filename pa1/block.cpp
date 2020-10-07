#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
/* your code here */
//std::cout << "width is "<< data.size() <<std::endl;
return data.size();

}

int Block::height() const
{
/* your code here */
if(data.size() != 0){
    return data[0].size();
}else{
    return 0;
}


}

void Block::render(PNG &im, int column, int row) const
{
/* your code here */
//std::cout << "reached render" <<std::endl;

for(int x = column; x< column + width(); x++){
        if(x>im.width()){
            break;
        }
    
        for(int y = row; y < row + height(); y++){
            if(y>=im.height()){
            break;
        }
        HSLAPixel * ptr = im.getPixel(x,y);
       
        *ptr = data[x-column][y-row];
        
    }
}
//std::cout << "reached render end" <<std::endl;
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
/* your code here */
//std::cout << "reached build" <<std::endl;
for(int x = column; x < column + width; x++){
    // col vector here 
    vector<HSLAPixel> verticalStrip;
    for(int y = row; y < row + height; y++){
        HSLAPixel * ptr = im.getPixel(x,y);
        verticalStrip.push_back(*ptr); 
    }
    data.push_back(verticalStrip);
}

//std::cout << "reached build end" << std::endl;
}

void Block::flip()
{
/* your code here */
std::cout << "reached flip" <<std::endl;
for(int x = 0; x < width(); x++){
    for(int y = 0; y < height()/2; y++){
        
        HSLAPixel temp = data[x][y];
        data[x][y] = data[x][height()-1-y];
        data[x][height()-1-y] = temp;

    }
    // for(int y = height()/2+1; y < height(); y++){
    //     data.at(x).at(y) = data.at(x).at(height()-y);
    // }
}
std::cout << "reached flip end" <<std::endl;

}

