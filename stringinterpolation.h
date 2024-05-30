#pragma once

char* stringInterpolation(char* _data, char* _aggregate, char* _value) {
	int dataLen = 0, aggregateLen = 0, valueLen = 0, aggregateIndex = -1;

	for (; _data[dataLen] != 0; dataLen++);
	for (; _aggregate[aggregateLen] != 0; aggregateLen++);
	for (; _value[valueLen] != 0; valueLen++);

	char* aggregate = new char[aggregateLen + 3];
	aggregateLen += 2;
	aggregate[0] = '{';
	aggregate[aggregateLen - 1] = '}';
	aggregate[aggregateLen] = '\0';
	for (int i = 1; i < aggregateLen - 1; i++)
		aggregate[i] = _aggregate[i - 1];

	if (aggregateLen > dataLen)
		return (char*)"";

	for (int i = 0; i < dataLen - aggregateLen + 1; i++)
		if (_data[i] == aggregate[0])
			for (int j = 0; j <= aggregateLen; j++) {
				if (j == aggregateLen) {
					aggregateIndex = i;
					break;
				}
				if (_data[i + j] != aggregate[j])
					break;
			}

	if (aggregateIndex == -1)
		return (char*)"";

	char* out = new char[dataLen - aggregateLen + valueLen + 1];
	for (int i = 0; i < aggregateIndex; i++)
		out[i] = _data[i];
	for (int i = 0; i < valueLen; i++)
		out[i + aggregateIndex] = _value[i];
	for (int i = 0; i < dataLen - aggregateIndex - aggregateLen; i++) {
		out[i + aggregateIndex + valueLen] = _data[i + aggregateIndex + aggregateLen];
	}

	out[dataLen - aggregateLen + valueLen] = '\0';

	return out;
}
