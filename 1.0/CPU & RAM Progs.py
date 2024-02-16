import psutil

# CPU Usage
print('The CPU usage is: ', psutil.cpu_percent(5))

# RAM Usage
print('RAM memory % used:', psutil.virtual_memory()[2]) # Retrieving usage of virtual_memory (%)
print('RAM Used (GB):', psutil.virtual_memory()[3]/1000000000) # Retrieving usage of virtual_memory (GB)
