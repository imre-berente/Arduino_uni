The following nodes are needed in the node.red palette:
@flowfuse/node-red-dashboard
node-red-node-serialport

The program receives serial port input in the form of [angle];[joint] and moves the miniSCARA joints accordingly and rogers the command in a serial message; or sends an error message if invalid command is received.
This was made as a task for the university robot course.
The serial port data comes from a node-red server running a flow, which is included. The dashboard has 4 elements:
* 2 sliders to control the joints
* a direct serial input field where you can send anything to the robot 
* a serial monitor that displays what the robot sent the user.