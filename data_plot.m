% Plot Space_Saving
clc
clear
close all

fid0 = fopen('space_saving_result.txt');
dataSS = textscan(fid0, '%s %d');

fid1 = fopen('count_min_result.txt');
dataCM = textscan(fid1, '%s %d');

fid2 = fopen('improved_count_min_result.txt');
dataICM = textscan(fid2, '%s %d');

fid3 = fopen('accurate_result.txt');
dataA = textscan(fid3, '%s %d');

data = [dataSS{2} dataCM{2} dataICM{2} dataA{2}];

figure
bar(data);
title('Frequency Plot Of Top 1000 words');
xlabel('Top 1000 Words in Alphabetical Order')
ylabel('Frequency')
legend('Space Saving', 'Count Min', 'Improved Count Min', 'Accurate Result');