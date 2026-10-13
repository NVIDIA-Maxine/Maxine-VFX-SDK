SETLOCAL
SET PATH=%PATH%;..\external\opencv\bin;

SET VIDEO_LIST=..\input\input_0_100_frames.mp4 ..\input\input_100_200_frames.mp4
BatchAigsEffectApp.exe --out_file=GreenScreen_%%04u.mp4 %VIDEO_LIST%

SET VIDEO_LIST=..\input\input_0_100_frames.mp4 ..\input\input_100_200_frames.mp4
BatchDenoiseEffectApp.exe --out_file=Denoise_%%04u.mp4 %VIDEO_LIST%