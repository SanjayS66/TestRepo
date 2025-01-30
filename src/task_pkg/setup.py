from setuptools import find_packages, setup

package_name = 'task_pkg'

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
    maintainer='sanjay',
    maintainer_email='sanjay@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "Drawcircle = task_pkg.Drawcircle:main",
            "control=task_pkg.controller:main",
            "togoal = task_pkg.goal:main",
            "drawd = task_pkg.drawd:main",
            "drawpoly = task_pkg.drawpoly:main",
            "sub=task_pkg.sub:main",
            "pub=task_pkg.pub:main"

        ],
    },
)
