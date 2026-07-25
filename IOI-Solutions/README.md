# IOI Solutions

My solutions to International Olympiad in Informatics (IOI) problems, organized by year and day.

## Structure

```
IOI-Solutions/
  <year>/
    <Day>_<Problem_Name>/
      solutions/
        <Problem_Name>.cpp     (starter file — rename/add more freely)
        Attempt2.cpp           (add as many solution attempts as you want)
      approach.md
      notes.md
```

## Fast lookup while practicing

This repo ships `ioi-cli.sh`, a shell helper for jumping straight to a problem:

```bash
echo "source \"$(pwd)/ioi-cli.sh\"" >> ~/.zshrc   # run once, from inside this folder
source ~/.zshrc

ioi souvenirs        # fuzzy-matches and opens the folder + solution.cpp in your editor
ioi 2023 robot       # add more keywords to disambiguate
ioil                 # list every problem folder
```

## Index

### 2025

- [2025 Practice — A Plus B Queries](2025/Practice_A_Plus_B_Queries/solutions/)
- [2025 Practice — Duplicated Binary Strings](2025/Practice_Duplicated_Binary_Strings/solutions/)
- [2025 Practice — Boring Game](2025/Practice_Boring_Game/solutions/)
- [2025 Practice — Magic Trick](2025/Practice_Magic_Trick/solutions/)
- [2025 Day1 — Souvenirs](2025/Day1_Souvenirs/solutions/)
- [2025 Day1 — Triple Peaks](2025/Day1_Triple_Peaks/solutions/)
- [2025 Day1 — World Map](2025/Day1_World_Map/solutions/)
- [2025 Day2 — Festival](2025/Day2_Festival/solutions/)
- [2025 Day2 — Migrations](2025/Day2_Migrations/solutions/)
- [2025 Day2 — Obstacles for a Llama](2025/Day2_Obstacles_for_a_Llama/solutions/)

### 2024

- [2024 Practice — A Plus B](2024/Practice_A_Plus_B/solutions/)
- [2024 Practice — Machine](2024/Practice_Machine/solutions/)
- [2024 Practice — Pyramids](2024/Practice_Pyramids/solutions/)
- [2024 Practice — Treasure](2024/Practice_Treasure/solutions/)
- [2024 Day1 — Nile](2024/Day1_Nile/solutions/)
- [2024 Day1 — Message](2024/Day1_Message/solutions/)
- [2024 Day1 — Tree](2024/Day1_Tree/solutions/)
- [2024 Day2 — Hieroglyphs](2024/Day2_Hieroglyphs/solutions/)
- [2024 Day2 — Mosaic](2024/Day2_Mosaic/solutions/)
- [2024 Day2 — Sphinx's Riddle](2024/Day2_Sphinxs_Riddle/solutions/)

### 2023

- [2023 Practice — A Plus B](2023/Practice_A_Plus_B/solutions/)
- [2023 Practice — Choreography](2023/Practice_Choreography/solutions/)
- [2023 Practice — Coreputer](2023/Practice_Coreputer/solutions/)
- [2023 Practice — Truck Driver](2023/Practice_Truck_Driver/solutions/)
- [2023 Practice — Lockpicking](2023/Practice_Lockpicking/solutions/)
- [2023 Day1 — Closing Time](2023/Day1_Closing_Time/solutions/)
- [2023 Day1 — Longest Trip](2023/Day1_Longest_Trip/solutions/)
- [2023 Day1 — Soccer Stadium](2023/Day1_Soccer_Stadium/solutions/)
- [2023 Day2 — Beech Tree](2023/Day2_Beech_Tree/solutions/)
- [2023 Day2 — Overtaking](2023/Day2_Overtaking/solutions/)
- [2023 Day2 — Robot Contest](2023/Day2_Robot_Contest/solutions/)

### 2022

- [2022 Practice — Magic Cards](2022/Practice_Magic_Cards/solutions/)
- [2022 Practice — Hoax Spreading](2022/Practice_Hoax_Spreading/solutions/)
- [2022 Practice — Team Contest](2022/Practice_Team_Contest/solutions/)
- [2022 Practice — Connected Towns](2022/Practice_Connected_Towns/solutions/)
- [2022 Day1 — Catfish Farm](2022/Day1_Catfish_Farm/solutions/)
- [2022 Day1 — Prisoner Challenge](2022/Day1_Prisoner_Challenge/solutions/)
- [2022 Day1 — Radio Towers](2022/Day1_Radio_Towers/solutions/)
- [2022 Day2 — Digital Circuit](2022/Day2_Digital_Circuit/solutions/)
- [2022 Day2 — Rarest Insects](2022/Day2_Rarest_Insects/solutions/)
- [2022 Day2 — Thousands Islands](2022/Day2_Thousands_Islands/solutions/)

### 2021

- [2021 Practice — Handcrafted Gift](2021/Practice_Handcrafted_Gift/solutions/)
- [2021 Practice — Jelly Flavours](2021/Practice_Jelly_Flavours/solutions/)
- [2021 Practice — Finding Routers](2021/Practice_Finding_Routers/solutions/)
- [2021 Practice — Robot](2021/Practice_Robot/solutions/)
- [2021 Day1 — Distributing Candies](2021/Day1_Distributing_Candies/solutions/)
- [2021 Day1 — Keys](2021/Day1_Keys/solutions/)
- [2021 Day1 — Fountain Parks](2021/Day1_Fountain_Parks/solutions/)
- [2021 Day2 — Mutating DNA](2021/Day2_Mutating_DNA/solutions/)
- [2021 Day2 — Dungeons Game](2021/Day2_Dungeons_Game/solutions/)
- [2021 Day2 — Bit Shift Registers](2021/Day2_Bit_Shift_Registers/solutions/)

### 2020

- [2020 Practice — Handcrafted Gift](2020/Practice_Handcrafted_Gift/solutions/)
- [2020 Practice — Painting Squares](2020/Practice_Painting_Squares/solutions/)
- [2020 Practice — Finding Routers](2020/Practice_Finding_Routers/solutions/)
- [2020 Practice — Jelly Flavours](2020/Practice_Jelly_Flavours/solutions/)
- [2020 Day1 — Comparing Plants](2020/Day1_Comparing_Plants/solutions/)
- [2020 Day1 — Connecting Supertrees](2020/Day1_Connecting_Supertrees/solutions/)
- [2020 Day1 — Carnival Tickets](2020/Day1_Carnival_Tickets/solutions/)
- [2020 Day2 — Packing Biscuits](2020/Day2_Packing_Biscuits/solutions/)
- [2020 Day2 — Counting Mushrooms](2020/Day2_Counting_Mushrooms/solutions/)
- [2020 Day2 — Stations](2020/Day2_Stations/solutions/)

### 2019

- [2019 Practice — Job Scheduling](2019/Practice_Job_Scheduling/solutions/)
- [2019 Practice — Lost in the Cycle](2019/Practice_Lost_in_the_Cycle/solutions/)
- [2019 Practice — Data Transfer](2019/Practice_Data_Transfer/solutions/)
- [2019 Practice — Packing](2019/Practice_Packing/solutions/)
- [2019 Day1 — Arranging Shoes](2019/Day1_Arranging_Shoes/solutions/)
- [2019 Day1 — Split the Attractions](2019/Day1_Split_the_Attractions/solutions/)
- [2019 Day1 — Rectangles](2019/Day1_Rectangles/solutions/)
- [2019 Day2 — Broken Line](2019/Day2_Broken_Line/solutions/)
- [2019 Day2 — Vision Program](2019/Day2_Vision_Program/solutions/)
- [2019 Day2 — Sky Walking](2019/Day2_Sky_Walking/solutions/)

### 2018

- [2018 Day1 — Combo](2018/Day1_Combo/solutions/)
- [2018 Day1 — Seats](2018/Day1_Seats/solutions/)
- [2018 Day1 — Werewolf](2018/Day1_Werewolf/solutions/)
- [2018 Day2 — Mechanical Doll](2018/Day2_Mechanical_Doll/solutions/)
- [2018 Day2 — Highway Tolls](2018/Day2_Highway_Tolls/solutions/)
- [2018 Day2 — Meetings](2018/Day2_Meetings/solutions/)

### 2017

- [2017 Day0 — Mountains](2017/Day0_Mountains/solutions/)
- [2017 Day0 — Cup of Jamshid](2017/Day0_Cup_of_Jamshid/solutions/)
- [2017 Day0 — Coins](2017/Day0_Coins/solutions/)
- [2017 Day1 — Nowruz](2017/Day1_Nowruz/solutions/)
- [2017 Day1 — Wiring](2017/Day1_Wiring/solutions/)
- [2017 Day1 — Toy Train](2017/Day1_Toy_Train/solutions/)
- [2017 Day2 — The Big Prize](2017/Day2_The_Big_Prize/solutions/)
- [2017 Day2 — Simurgh](2017/Day2_Simurgh/solutions/)
- [2017 Day2 — Ancient Books](2017/Day2_Ancient_Books/solutions/)

### 2016

- [2016 Day0 — Mini Tetris](2016/Day0_Mini_Tetris/solutions/)
- [2016 Day0 — Reversing a Sequence](2016/Day0_Reversing_a_Sequence/solutions/)
- [2016 Day0 — Laugh Analysis](2016/Day0_Laugh_Analysis/solutions/)
- [2016 Day0 — Martian DNA](2016/Day0_Martian_DNA/solutions/)
- [2016 Day1 — Detecting Molecules](2016/Day1_Detecting_Molecules/solutions/)
- [2016 Day1 — Roller Coaster Railroad](2016/Day1_Roller_Coaster_Railroad/solutions/)
- [2016 Day1 — Shortcut](2016/Day1_Shortcut/solutions/)
- [2016 Day2 — Paint By Numbers](2016/Day2_Paint_By_Numbers/solutions/)
- [2016 Day2 — Unscrambling a Messy Bug](2016/Day2_Unscrambling_a_Messy_Bug/solutions/)
- [2016 Day2 — Aliens](2016/Day2_Aliens/solutions/)

### 2015

- [2015 Day1 — Boxes with Souvenirs](2015/Day1_Boxes_with_Souvenirs/solutions/)
- [2015 Day1 — Scales](2015/Day1_Scales/solutions/)
- [2015 Day1 — Teams](2015/Day1_Teams/solutions/)
- [2015 Day2 — Horses](2015/Day2_Horses/solutions/)
- [2015 Day2 — Sorting](2015/Day2_Sorting/solutions/)
- [2015 Day2 — Towns](2015/Day2_Towns/solutions/)

### 2014

- [2014 Day1 — Rail](2014/Day1_Rail/solutions/)
- [2014 Day1 — Wall](2014/Day1_Wall/solutions/)
- [2014 Day1 — Game](2014/Day1_Game/solutions/)
- [2014 Day2 — Gondola](2014/Day2_Gondola/solutions/)
- [2014 Day2 — Friend](2014/Day2_Friend/solutions/)
- [2014 Day2 — Holiday](2014/Day2_Holiday/solutions/)

### 2013

- [2013 Day1 — Dreaming](2013/Day1_Dreaming/solutions/)
- [2013 Day1 — Art Class](2013/Day1_Art_Class/solutions/)
- [2013 Day1 — Wombats](2013/Day1_Wombats/solutions/)
- [2013 Day2 — Cave](2013/Day2_Cave/solutions/)
- [2013 Day2 — Robots](2013/Day2_Robots/solutions/)
- [2013 Day2 — Game](2013/Day2_Game/solutions/)

### 2012

- [2012 Day1 — Pebbling Odometer](2012/Day1_Pebbling_Odometer/solutions/)
- [2012 Day1 — Parachute Rings](2012/Day1_Parachute_Rings/solutions/)
- [2012 Day1 — Crayfish Scrivener](2012/Day1_Crayfish_Scrivener/solutions/)
- [2012 Day2 — Ideal City](2012/Day2_Ideal_City/solutions/)
- [2012 Day2 — Last Supper](2012/Day2_Last_Supper/solutions/)
- [2012 Day2 — Jousting Tournament](2012/Day2_Jousting_Tournament/solutions/)

### 2011

- [2011 Day1 — Tropical Garden](2011/Day1_Tropical_Garden/solutions/)
- [2011 Day1 — Race](2011/Day1_Race/solutions/)
- [2011 Day1 — Rice Hub](2011/Day1_Rice_Hub/solutions/)
- [2011 Day2 — Crocodile's Underground City](2011/Day2_Crocodiles_Underground_City/solutions/)
- [2011 Day2 — Dancing Elephants](2011/Day2_Dancing_Elephants/solutions/)
- [2011 Day2 — Parrots](2011/Day2_Parrots/solutions/)

### 2010

- [2010 Day1 — Cluedo](2010/Day1_Cluedo/solutions/)
- [2010 Day1 — Hotter Colder](2010/Day1_Hotter_Colder/solutions/)
- [2010 Day1 — Quality of Living](2010/Day1_Quality_of_Living/solutions/)
- [2010 Day1 — Languages](2010/Day1_Languages/solutions/)
- [2010 Day2 — Memory](2010/Day2_Memory/solutions/)
- [2010 Day2 — Traffic Congestion](2010/Day2_Traffic_Congestion/solutions/)
- [2010 Day2 — Maze](2010/Day2_Maze/solutions/)
- [2010 Day2 — Saveit](2010/Day2_Saveit/solutions/)

### 2009

- [2009 Day1 — Archery](2009/Day1_Archery/solutions/)
- [2009 Day1 — Hiring](2009/Day1_Hiring/solutions/)
- [2009 Day1 — Poi](2009/Day1_Poi/solutions/)
- [2009 Day1 — Raisins](2009/Day1_Raisins/solutions/)
- [2009 Day2 — Garage](2009/Day2_Garage/solutions/)
- [2009 Day2 — Mecho](2009/Day2_Mecho/solutions/)
- [2009 Day2 — Regions](2009/Day2_Regions/solutions/)
- [2009 Day2 — Salesman](2009/Day2_Salesman/solutions/)

### 2008

- [2008 Day1 — Type Printer](2008/Day1_Type_Printer/solutions/)
- [2008 Day1 — Islands](2008/Day1_Islands/solutions/)
- [2008 Day1 — Fish](2008/Day1_Fish/solutions/)
- [2008 Day2 — Linear Garden](2008/Day2_Linear_Garden/solutions/)
- [2008 Day2 — Pyramid Base](2008/Day2_Pyramid_Base/solutions/)
- [2008 Day2 — Teleporters](2008/Day2_Teleporters/solutions/)

### 2007

- [2007 Day1 — Aliens](2007/Day1_Aliens/solutions/)
- [2007 Day1 — Flood](2007/Day1_Flood/solutions/)
- [2007 Day1 — Sails](2007/Day1_Sails/solutions/)
- [2007 Day2 — Miners](2007/Day2_Miners/solutions/)
- [2007 Day2 — Pairs](2007/Day2_Pairs/solutions/)
- [2007 Day2 — Training](2007/Day2_Training/solutions/)

### 2006

- [2006 Day1 — Deciphering the Mayan Writing](2006/Day1_Deciphering_the_Mayan_Writing/solutions/)
- [2006 Day1 — Pyramid](2006/Day1_Pyramid/solutions/)
- [2006 Day1 — Forbidden Subgraph](2006/Day1_Forbidden_Subgraph/solutions/)
- [2006 Day2 — The Valley of Mexico](2006/Day2_The_Valley_of_Mexico/solutions/)
- [2006 Day2 — Joining Points](2006/Day2_Joining_Points/solutions/)
- [2006 Day2 — A Black Box Game](2006/Day2_A_Black_Box_Game/solutions/)

### 2005

- [2005 Day1 — Garden](2005/Day1_Garden/solutions/)
- [2005 Day1 — Mountain](2005/Day1_Mountain/solutions/)
- [2005 Day1 — Mean Sequence](2005/Day1_Mean_Sequence/solutions/)
- [2005 Day2 — Birthday](2005/Day2_Birthday/solutions/)
- [2005 Day2 — Rectangle Game](2005/Day2_Rectangle_Game/solutions/)
- [2005 Day2 — Rivers](2005/Day2_Rivers/solutions/)

### 2004

- [2004 Day1 — Artemis](2004/Day1_Artemis/solutions/)
- [2004 Day1 — Hermes](2004/Day1_Hermes/solutions/)
- [2004 Day1 — Polygon](2004/Day1_Polygon/solutions/)
- [2004 Day2 — Empodia](2004/Day2_Empodia/solutions/)
- [2004 Day2 — Phidias](2004/Day2_Phidias/solutions/)
- [2004 Day2 — Farmer](2004/Day2_Farmer/solutions/)

### 2003

- [2003 Day1 — Trail Maintenance](2003/Day1_Trail_Maintenance/solutions/)
- [2003 Day1 — Comparing Code](2003/Day1_Comparing_Code/solutions/)
- [2003 Day1 — Reverse](2003/Day1_Reverse/solutions/)
- [2003 Day2 — Guess Which Cow](2003/Day2_Guess_Which_Cow/solutions/)
- [2003 Day2 — Amazing Robots](2003/Day2_Amazing_Robots/solutions/)
- [2003 Day2 — Seeing the Boundary](2003/Day2_Seeing_the_Boundary/solutions/)

### 2002

- [2002 Day1 — The Troublesome Frog](2002/Day1_The_Troublesome_Frog/solutions/)
- [2002 Day1 — Utopia Divided](2002/Day1_Utopia_Divided/solutions/)
- [2002 Day1 — XOR](2002/Day1_XOR/solutions/)
- [2002 Day2 — Batch Scheduling](2002/Day2_Batch_Scheduling/solutions/)
- [2002 Day2 — Bus Terminals](2002/Day2_Bus_Terminals/solutions/)
- [2002 Day2 — Two Rods](2002/Day2_Two_Rods/solutions/)
