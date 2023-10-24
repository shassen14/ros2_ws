from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
             package='learning_tf2_cpp',
             executable='static_turtle_tf2_broadcaster',
             arguments = [ '0', '0', '1', '0', '0', '0']
            #  arguments = ['--x', '0', '--y', '0', '--z', '1', '--yaw', '0', '--pitch', '0', '--roll', '0', '--frame-id', 'world', '--child-frame-id', 'mystaticturtle']

        ),
    ])