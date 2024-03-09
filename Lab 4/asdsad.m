n=0:1/48000:100;
sin1 = sin(2*pi*n);
sin2 = sin(400000*pi*n);
Hd = untitled;
x1=filter(Hd,sin1+sin2);
plot(abs(fftshift(fft(x1))));