//void splitInto2(char* str, char* dst1, char* dst2) {
//	char d1[] = "<d1>";
//	char d3[] = "<d3>";
//
//	char* catchDateTime = strstr(str, d1);
//	char* catchEndLine = strstr(str, d3);
//
//	memcpy(dst1, str, catchDateTime - str);
//	dst1[catchDateTime - str] = 0;
//
//	strcpy(dst2, catchDateTime + sizeof(d1) - 1);
//	return;
//}
//void secondSplit(char* str, char* dst1, char* dst2) {
//	char d2[] = "<d2>"; char d3[] = "<d3>";
//
//	char* catchFilename = strstr(str, d2);
//	memcpy(dst1, str, catchFilename - str);
//	dst1[catchFilename - str] = 0;
//
//	char* catchEndLine = strstr(str, d3);
//	memcpy(dst2, catchFilename + strlen(d2), catchEndLine - (catchFilename + strlen(d2)));
//	dst2[catchEndLine - (catchFilename + strlen(d2))] = 0;
//}
//void splitInto3(char* str, char* timeDate, char* filename, char* data) {
//	char temp[150];
//	splitInto2(str, timeDate, temp);
//	secondSplit(temp, filename, data);
//}
//tm makeTimeObj(char* time_details) {
//	tm tm;
//	char* date = strtok(time_details, " ");
//	char* time = strtok(NULL, "\n");
//	tm.tm_mday = atoi(strtok(date, "/"));
//	tm.tm_mon = atoi(strtok(NULL, "/"));
//	tm.tm_year = atoi(strtok(NULL, "/"));
//	tm.tm_hour = atoi(strtok(time, ":"));
//	tm.tm_min = atoi(strtok(NULL, ":"));
//	tm.tm_sec = atoi(strtok(NULL, ":"));
//	return tm;
//}