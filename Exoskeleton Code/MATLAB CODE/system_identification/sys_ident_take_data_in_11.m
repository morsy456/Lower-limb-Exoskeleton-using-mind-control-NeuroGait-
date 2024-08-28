close all
clear all
clc

S=load('E:\4 th year Mechatronics department\Graduation Project\Exo\3-Control\system_identification\volt_angl.txt');

out_put=S(:,2);
In_put=S(:,3);
all_st=S(:,1);

collect_st=[];
for  i=1:1:(length(all_st)-1)
    new_collect=(all_st(i+1))-(all_st(i));
    collect_st = [collect_st new_collect];
end
Time_sample = sum(collect_st)/length(collect_st)*0.000001;
% Time_sample = 0.041;
get_sys=iddata(out_put,In_put,Time_sample)
plot(get_sys)
% m12=tfest(get_sys,6,6)
% m12=tfest(get_sys,3,1)
% % % % % % % % % % % % % % % %  m12=tfest(get_sys,7,7)%%%%%imoprtant
% % m12=tfest(get_sys,7,6)
% m12=tfest(get_sys,8,8)
% m12=tfest(get_sys,9,9)

most_FiTTing_FUNC12=tfest(get_sys,7,7)
compare(get_sys,most_FiTTing_FUNC12)
DIGITAL_TF = c2d(most_FiTTing_FUNC12,Time_sample,'ZOH')

Model=armax(get_sys,[3 3 2 1])
den=Model.A
num=Model.B
Model_sys=tf(num,den,Time_sample)
