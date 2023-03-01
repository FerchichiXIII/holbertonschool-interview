#!/usr/bin/python3


import sys
from collections import defaultdict

# Define a dictionary to keep track of the counts of each status code
status_counts = defaultdict(int)

# Initialize total file size to 0
total_file_size = 0

# Read from stdin line by line
for i, line in enumerate(sys.stdin):
    try:
        # Parse the line according to the input format
        ip_address, date, request, status_code, file_size = line.split(' ')
        request = request.strip('"')
        if request != 'GET /projects/260 HTTP/1.1':
            continue
        status_code = int(status_code)
        file_size = int(file_size)

        # Update the total file size
        total_file_size += file_size

        # Update the count of the status code
        status_counts[status_code] += 1

        # Print statistics every 10 lines
        if i > 0 and i % 10 == 0:
            print(f'Total file size: {total_file_size}')
            for status_code in sorted(status_counts.keys()):
                print(f'{status_code}: {status_counts[status_code]}')

    except KeyboardInterrupt:
        # If CTRL + C is pressed, print the final statistics and exit
        print(f'Total file size: {total_file_size}')
        for status_code in sorted(status_counts.keys()):
            print(f'{status_code}: {status_counts[status_code]}')
        sys.exit()
    except:
        # If the line doesn't match the input format, skip it
        continue
