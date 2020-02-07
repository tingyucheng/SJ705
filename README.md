SJ705 Package Tutorial 
========
## Set up the environment
### Environment
* Ubuntu 16.04 LTS OS
* ROS Kinetic 1.12.14
* Gazebo 7.16.0

## Package installation
### Installation steps
1. Create ROS workspace
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```
2. Clone 
```
git clone https://github.com/tingyucheng/SJ705.git
```
3. Install ROS dependencies using the rosdep install command
```
$ cd ~/catkin_ws
$ rosdep install --from-paths src --ignore-src --rosdistro=kinetic -y
```
4. Run catkin_make in your workspace to build the project
```
$ cd ~/catkin_ws
$ catkin_make
```

### Simulation
* To run simulator by using Gazebo

```
cd catkin_ws
source devel/setup.bash
```
Run the code above every time to source your setup.*sh file if you open a new terminal.
  
Then run the code
```
$ roslaunch sj705_gazebo sj705_world.launch
```
You will see sj705 robot in a simulation world.
   
Open a new terminal, source your setup.*sh file as before, and then run the code to control joints of the robot.
```
$ roslaunch sj705_control sj705_control.launch
```
Now, to control robot by publishing some information to it, open a new terminal and source your setup.*sh file.
Then run the code
```
$ rosrun publisher_file sj705_instruction 
```

## DH table of sj705

| Links  | alpha | a | d  | theta |
|:-----:|:----------:|:------:| ------ |:--------:|
|  1  |     -90    |   0    | 0.1985 |    q1    |
|  2  |     90     |   0    | 0      |    q2   |
|  3  |     -90    |   0    | 0.31   |    q3    |
|  4  |     90     |   0    | 0      |    q4    |
|  5  |    -90     |   0    | 0.218  |    q5    |
|  6  |     90     |   0    | 0      |    q6    |
|  7  |     0      |   0    | 0.1    |    q7     |
