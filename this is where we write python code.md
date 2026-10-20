Baisc code of py

#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

def main(args=None):
    rclpy.init(args=args)
    node = Node("py_Test")
    node.get_logger().info("Hello ROS2")
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()


and also the latest my_fisrst _node.py is the template and can be reused and its the oop pythin program this  is where it keeps repeateing hello hello


#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("py_Test")
        self.get_logger().info("Hello ROS2")
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().info("Hello")

def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()




this code is after the insertion of timer 
so inevry hello iteration it shows the timer cousnt as 0 1 2 3  etc till runtime 
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("py_Test")
        self.count = 0
        self.get_logger().info("Hello ROS2")
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.get_logger().info("Hello " + str(self.count))
        self.count += 1

def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()


this is the setup code. for pyhton ececutable name node
from setuptools import find_packages, setup

package_name = 'my_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sickshank',
    maintainer_email='shashankmahesh824@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "py_node = my_py_pkg.my_first_node:main"
        ],
    },
)
