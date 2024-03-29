function y = fir_lp(x)
%FIR_LP Filters input x and returns output y.

% MATLAB Code
% Generated by MATLAB(R) 9.10 and DSP System Toolbox 9.12.
% Generated on: 11-Nov-2021 21:26:59

%#codegen

% To generate C/C++ code from this function use the codegen command. Type
% 'help codegen' for more information.

persistent Hd;

if isempty(Hd)
    
    % The following code was used to design the filter coefficients:
    % % FIR Window Lowpass filter designed using the FIR1 function.
    %
    % % All frequency values are in Hz.
    % Fs = 44100;  % Sampling Frequency
    %
    % Fpass = 5000;     % Passband Frequency
    % Fstop = 11000;    % Stopband Frequency
    % Dpass = 0.01;     % Passband Ripple
    % Dstop = 0.01;     % Stopband Attenuation
    % flag  = 'scale';  % Sampling Flag
    %
    % % Calculate the order from the parameters using KAISERORD.
    % [N,Wn,BETA,TYPE] = kaiserord([Fpass Fstop]/(Fs/2), [1 0], [Dstop Dpass]);
    %
    % % Calculate the coefficients using the FIR1 function.
    % b  = fir1(N, Wn, TYPE, kaiser(N+1, BETA), flag);
    
    Hd = dsp.FIRFilter( ...
        'Numerator', [-0.00143445751405165 0.0083783939871379 ...
        0.0169339029845171 -0.000427005008694046 -0.0421544666139583 ...
        -0.0528250219548423 0.0321537489930314 0.199746870555997 ...
        0.339628034570863 0.339628034570863 0.199746870555997 0.0321537489930314 ...
        -0.0528250219548423 -0.0421544666139583 -0.000427005008694046 ...
        0.0169339029845171 0.0083783939871379 -0.00143445751405165]);
end

y = step(Hd,double(x));


% [EOF]
