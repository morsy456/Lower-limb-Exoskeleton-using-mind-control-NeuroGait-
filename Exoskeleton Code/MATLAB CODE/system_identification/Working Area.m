% Parameters
a1 = 0.4; % Length of the thigh (in meters)
a2 = 0.4; % Length of the shank (in meters)

% Joint limits (converted to radians)
theta1_min = deg2rad(-20);
theta1_max = deg2rad(130);
theta2_min = deg2rad(0);
theta2_max = deg2rad(130);

% Generate theta values
theta1_values = linspace(theta1_min, theta1_max, 200);
theta2_values = linspace(theta2_min, theta2_max, 200);

% Initialize arrays to store coordinates
x_coords = [];
y_coords = [];

% Compute the workspace by iterating over theta1 and theta2
for theta1 = theta1_values
    for theta2 = theta2_values
        x = a1 * cos(theta1) + a2 * cos(theta1 + theta2);
        y = a1 * sin(theta1) + a2 * sin(theta1 + theta2);
        x_coords = [x_coords, x];
        y_coords = [y_coords, y];
    end
end

% Plot the workspace
figure;
plot(x_coords, y_coords, 'b.');
title('Workspace of the 2-DOF Leg Exoskeleton');
xlabel('x (m)');
ylabel('y (m)');
grid on;
axis equal;
