[top]
components : laser@Laser 
components : driver@Driver

out : light
in : data

Link : data data@driver
Link : current@driver current@laser
Link : light@laser light

[laser]
processingTime : 00:00:02:00

[driver]
processingTime : 00:00:02:00



