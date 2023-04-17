/*
 * Name:            Jai Agarwal
 * Date Submitted:  3/13/23
 * Lab Section:     002
 * Assignment Name: Lab 6 - finding closest pair
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

// function to calculate the distance between two points
// takes two struct of type point as args
// returns the distance between the two pairs
double calcDistance(point p1, point p2){
  return (double)sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename){
  //open the file
  ifstream inFile;
  inFile.open(filename);

  int b, totalPoints, xpos, ypos;
  double interval, x = 0, y = 0, min = 1, distance;
  struct point pair;  // declare a point to use

  int changeY[] = {0, 0, 1, 1, 1, -1, -1, -1}; // for row
  int changeX[] = {1, -1, 0, 1, -1, 0, 1, -1}; // for col

  inFile >> totalPoints;
  b = sqrt(totalPoints);
  interval = (double)1/b;
  vector<vector<vector<point>>> plane(b, vector<vector<point>>(b)); // initialize the plane
  
  for (int i = 0; i < totalPoints; i++){
    inFile >> pair.x;   // get x val
    inFile >> pair.y;   // get y val

    xpos = pair.x/interval;   // hash for x val
    ypos = pair.y/interval;   // hash for y val

    plane[xpos][ypos].push_back(pair); // push the pair into the cell
  }

  for (int r = 0; r < b; r++){  //row
    for (int c = 0; c < b; c++){  //col
      for (int k = 0; k < plane[r][c].size(); k++){ //cell

        point tempP = plane[r][c][k]; // save this current point in cell
        int kNext = k + 1;

        // call calcDistance for every element in the cell 
        while (kNext < plane[r][c].size()){
          distance = calcDistance(tempP, plane[r][c][kNext]);
          if(distance < min){
            min = distance;
          }
          kNext++;
        }
          
        // then check neighbors
        int testX, testY, x, y, z;
        for (int i = 0; i < 8; i++){  // loop for 8 neighbors 
          testY = r, testX = c;
          testY += changeY[i];
          testX += changeX[i];
          if(testY > 0 && testY < b)
            y = testY;
          if(testX > 0 && testX < b)
            x = testX;
          z = 0;
          while(z < plane[x][y].size()){
            if (plane[x][y][z].x != 0 && plane[x][y][z].y != 0){ // if the point pair is not 0,0
              distance = calcDistance(tempP, plane[x][y][z]);
              if(distance < min && distance != 0){
                min = distance;
              }
            }
            z++;
          }
        }
        plane[r][c][k] = {0,0}; // set this point to 0,0 to signify it has been used     
      }
    } 
  }

  return min;
}


// int main()
// {
//     double min;
//     string filename;
//     // cout << "File with list of points within unit square: ";
//     // cin >> filename;
//     min = closestPair("points10.txt");
//     cout << setprecision(16);
//     cout << "Distance between closest pair of points: " << min << endl;
//     return 0;
// }