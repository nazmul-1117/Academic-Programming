

x = -pi : 0.1 : pi;
y = zeros(size(0));

for i = 1 : length(x)
  y(i) = sin(x(i));
end

plot(x, y, "g*");
title("Sine Wave Plot from -π to π");
xlabel("x");
ylabel("sin(x)");
grid on;

