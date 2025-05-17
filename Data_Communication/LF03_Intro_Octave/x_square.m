x = -10 : 0.1 : 10;
y = zeros(size(x));

% Method 1
%y = x.^2;

#method 2
for i = 1: length(x)
  y(i) = x(i)^2;
end

plot(x, y, "g+");
title("Y = X^2");
xlabel("x");
ylabel("x^2");
grid on;
