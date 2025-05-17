## 0 -> High
## 1 -> Low

##Encoding
bits = [1 0 1 0 1 0];
bitrate = 1;
sample = 10;

T = length(bits)/bitrate;
N = length(bits)*sample;

dt = T/N;
t = 0: dt : T;

x = zeros(1, length(t));
lastbit = 1;

for i = 1:length(bits)
  if bits(i) == 0
    x((i-1)*sample+1 : sample*i) = -lastbit;
    lastbit = -lastbit;

  else
    x((i-1)*sample+1 : sample*i) = lastbit;
  endif
end
plot(t, x, "b");
title("NRZ-I Encoding");
xlabel("Sample");
ylabel("Voltage");


##Decode
lastbit = 1;
counter = 0;
result = [];

for i = 1 : length(t)
  if counter < t(i)
    counter = counter + 1;
    if x(i) != lastbit
      result(counter) = 0;
      lastbit = -lastbit;
    else
      result(counter) = 1;
    endif
  endif
end
disp("NRZ-I Decoding");
disp(result);














