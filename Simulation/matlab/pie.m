% Y=[10 13 40 50];%����Y�V�q��
% subplot(2,2,1), pie3(Y)
% title('1.���[����Х�');
% subplot(2,2,2), pie3(Y,[0 0 0 1]) 
% title('2.�ĥ|�������z��');
% subplot(2,2,3), pie3(Y,{'�F��','�賡','�n��','�_��'})  
% title('3.�]�w�U�զW��'); 
% subplot(2,2,4), pie3(Y,[0 0 1 1],{'�F��','�賡','�n��','�_��'})  
% title('4.�]�w�W�٤Ϋn�_���z��'); 

% x = [1 3 0.5 2.5 2];
% explode = [0 1 0 0 0];
% pie3(x,explode)
% colormap jet

% x = [1 3 0.5 2.5 2];
% explode = [0 1 0 0 0];
% pie3(x,explode)
% colormap hsv

%���פ�
%ftp
x = [91.43, 8.57];
explode = [0 1];
label = {'���\�v91%','���Ѳv9%'};
subplot(3,2,1)
pie3(x, explode, label)
% pie3(x, explode)
title('ftp�L����');
colormap jet

x = [100, 0];
explode = [0 1];
label = {'���\�v100%','���Ѳv0%'};
subplot(3,2,2)
pie3(x, explode, label)
% pie3(x, explode)
title('ftp������');
colormap jet


%voip
x = [86.84, 13.16];
explode = [0 1];
label = {'���\�v87%','���Ѳv13%'};
subplot(3,2,3)
pie3(x, explode, label)
% pie3(x, explode)
title('voip�L����');
colormap jet

x = [100, 0];
explode = [0 1];
label = {'���\�v100%','���Ѳv0%'};
subplot(3,2,4)
pie3(x, explode, label)
% pie3(x, explode)
title('voip������');
colormap jet


%stm
x = [74.07, 25.93];
explode = [0 1];
label = {'���\�v74%','���Ѳv26%'};
subplot(3,2,5)
pie3(x, explode, label)
% pie3(x, explode)
title('stm�L����');
colormap jet

x = [81.48, 18.52];
explode = [0 1];
label = {'���\�v81%','���Ѳv19%'};
subplot(3,2,6)
pie3(x, explode, label)
% pie3(x, explode)
title('stm������');
colormap jet
