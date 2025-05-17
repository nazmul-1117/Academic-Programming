bits = [1 0 1];
bitrate = 1;
n = 1000;

T = length(bits)/bitrate;
N = n*length(bits);
dt = T/N;
t = 0:dt:T;

x = zeros(1,length(t));

% NRZ-L Encoding
for i=1:length(bits)
  if bits(i) == 1
    x(((i-1)*n)+1:i*n) = 1;  % High level for bit '1'
  else
    x(((i-1)*n)+1:i*n) = -1; % Low level for bit '0'
  end
end

plot(t, x, 'Linewidth', 3);
title('NRZ-L Encoding');
xlabel('Time');
ylabel('Amplitude');
grid on;
ylim([-1.5 1.5]); % Adjust y-axis limits for better visualization

% NRZ-L Decoding
result = [];
for i = 1:length(bits)
  % Find the middle sample of each bit interval
  middle_sample_index = round(((i-1)*n) + (n/2));
  if middle_sample_index <= length(x)
    if x(middle_sample_index) > 0
      result(i) = 1;
    else
      result(i) = 0;
    end
  end
end

disp('NRZ-L Decoding:');
disp(result);
