[top]
components : photodiode@Photodiode 
components : aTIA@TIA

in : light
out : data

Link : light light@photodiode
Link : current@photodiode current@aTIA
Link : data@aTIA data

[photodiode]
processingTime : 00:00:02:00

[aTIA]
processingTime : 00:00:02:00



