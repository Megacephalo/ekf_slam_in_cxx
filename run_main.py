#! /usr/bin/env python3
#! /usr/bin/python3

import os
import sys

if __name__=='__main__':
    print('Running EKF SLAM')

    dataset_dir = 'data/'
    sensor_dataset = dataset_dir + 'sensor_data.dat'
    # sensor_dataset = dataset_dir + 'short_sensor_data.dat'
    world_dataset = dataset_dir + 'world.dat'

    if not sensor_dataset:
    	print('{} does not exist and cannot get any information on sensor observations.')
    	sys.exit()

    if not world_dataset:
    	print('{} does not exist and cannot get any information on the mapping information.')
    	sys.exit()

    # If all files exist, let's go through the normal procedure
    bin_dir = 'bin/'
    exe_name = bin_dir + 'EKF_SLAM_in_cxx'

    cmd = exe_name + ' ' + sensor_dataset + ' ' + world_dataset
    print('Sending command : {}'.format(cmd))
    os.system(cmd)
    print('Done! ')