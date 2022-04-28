[top]
components : polarizationCommand@PolarizationCommand 
components : commandModulation@CommandModulation 
components : emissionLaser@EmissionLaser 

out : y
in : x

Link : x in1@commandModulation
Link : x in1@polarizationCommand
Link : out1@commandModulation in1@emissionLaser
Link : out1@polarizationCommand in2@commandModulation
Link : out2@polarizationCommand in2@emissionLaser
Link : out1@emissionLaser y 

[polarizationCommand]
processingTime : 00:00:02:00



[commandModulation]
processingTime : 00:00:02:00

[emissionLaser]
processingTime : 00:00:02:00



