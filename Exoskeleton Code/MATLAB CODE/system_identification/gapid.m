clear all, close all, clc

dt = 0.001;
t = tf('s');
G = (((2.246*10^4)*t^2)-((4.209*10^5)*t)+4.407*10^6)/(t^3+(318.9*t^2)+3591*t+(3.155*10^4));

options = optimoptions(@ga,'PopulationSize',25,'MaxGenerations',10);
[x,fval] = ga(@(K)pidtest(G,dt,K),3,-eye(3),zeros(3,1),[],[],[],[],[],options);