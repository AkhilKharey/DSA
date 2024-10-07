% Simplified DSSS BPSK Simulation with Spectral Plots (Corrected)

% Parameters
numBits = 1e3;
chipRate = 10;
snr = 10;
fs = 1000;

% Generate random bits and BPSK modulation
dataBits = randi([0 1], numBits, 1);
modData = 2 * dataBits - 1;
// dono mile pyar se ro diye dekhte dekhte
% Generate PN sequence
pnSeq = 2 * randi([0 1], numBits * chipRate, 1) - 1;

% Spread the signal
spreadSig = repelem(modData, chipRate) .* pnSeq;

% Transmit over AWGN channel
rxSig = awgn(spreadSig, snr, 'measured');

% Despread the signal
despreadSig = rxSig .* pnSeq;
despreadSigMatrix = reshape(despreadSig, chipRate, []);
despreadBits = sum(despreadSigMatrix, 1)' / chipRate;

% BPSK Demodulation
rxBits = despreadBits > 0;

% Calculate Bit Error Rate (BER)
BER_DSSS = sum(dataBits ~= rxBits) / numBits;

% Frequency axis for spectra
n = length(spreadSig);
freqs = (-n/2:n/2-1) * (fs / n);

% Compute spectra with zero-padding to length 'n'
messageSpec = fftshift(fft(modData, n));
pnSpec = fftshift(fft(pnSeq, n));
spreadSpec = fftshift(fft(spreadSig, n));
rxSpec = fftshift(fft(rxSig, n));
despreadSpec = fftshift(fft(despreadSig, n));
demodSpec = fftshift(fft(despreadBits, n));

% Plotting
figure;

subplot(3,2,1);
plot(freqs, abs(messageSpec));
title('Message Signal Spectrum');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

subplot(3,2,2);
plot(freqs, abs(pnSpec));
title('PN Code Spectrum');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

subplot(3,2,3);
plot(freqs, abs(spreadSpec));
title('Spread Signal Spectrum');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

subplot(3,2,4);
plot(freqs, abs(rxSpec));
title('Received Signal Spectrum');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

subplot(3,2,5);
plot(freqs, abs(despreadSpec));
title('Despread Signal Spectrum');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

subplot(3,2,6);
plot(freqs, abs(demodSpec));
title('Demodulated Signal Spectrum (Before Decision Device)');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

fprintf('DSSS BER: %e\n', BER_DSSS);
