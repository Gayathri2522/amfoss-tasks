# Commands used for this task:-
1) mkdir Coordinates-Location
  cd Coordinates-Location
2) mkdir North
  cd North
2i) gedit NDegree.txt
    Answer: 9 degrees
2ii) gedit NMinutes.txt
     Answer: 5'
2iii) gedit NSeconds.txt
      Answer: 38"
2iv) cat NDegree.txt NMinutes.txt NSeconds.txt >> NorthCoordinate.txt
2v) cp -i NorthCoordinate.txt ../
    rm NorthCoordinate.txt
    cd ../
    mv NorthCoordinate.txt North.txt

4) mkdir East
   cd East
4i) gedit EDegree.txt
   Answer: 76 degrees
4ii) gedit EMinutes.txt
   Answer: 29'
4iii) gedit ESeconds.txt
   Answer:30.8"
4iv) cat EDegree.txt EMinutes.txt ESeconds.txt >> EastCoordinate.txt
4v) cp -i EastCoordinate.txt ../
    rm EastCoordinate.txt
    cd ../
    mv EastCoordinate.txt East.txt

5)  cat North.txt East.txt >> Location-Coordinate.txt

# Git Commands

git add .
git commit -m "Initial commit"
git push origin main


   
