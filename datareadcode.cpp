#include<fstream>
#include<cstdio>
#include<string>
#include<iostream>
// #include<format>
using namespace std;

const string dir_path = "./adjustdata/";

int main(){
    string file_path = dir_path + "0.dat";
    cout<<file_path<<endl;
    FILE* file = fopen(file_path.c_str(), "rb");
    if (file == NULL){
        cout<< "Open file filed." << endl;
        return 0;
    }
    printf("%d\n", sizeof(float));
    float LookAt[3], Up[3], vFov[4];
    for (int i = 0; i < 3; i++)
	{
		fread(&LookAt[i], sizeof(LookAt[i]), 1, file);

        cout<<"Look at(" << i << ") :" << LookAt[i] <<endl;
	}
    for (int i = 0; i < 3; i++)
    {
        fread(&Up[i], sizeof(Up[i]), 1, file);

        cout<<"Up (" << i << ") :" << Up[i] << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        fread(&vFov[i], sizeof(vFov[i]), 1, file);

        cout<<"Fov (" << i << ") :" << vFov[i] << endl;
    }
    return 0;
}

// 		FMatrix CameraMat = makeLookat(FVector(0, 0, 0), FVector(LookAt[0], LookAt[1], -LookAt[2]), FVector(Up[0], Up[1], -Up[2]));

// 		g_CameraMat = CameraMat;
// 		FQuat quat = getRotate(CameraMat);
// 		Quaternion qquat(quat.X, quat.Y, quat.Z, quat.W);
// 		double HPR[3];
// 		quaternion2Euler(qquat, HPR, zxy);
// 		rotator = FRotator(-HPR[1] * 180 / PI, HPR[0] * 180 / PI, HPR[2] * 180 / PI);

// 	g_rotator = rotator;
// 	return rotator;
// }

// FQuat getRotate(FMatrix mat)
// {
// 	FQuat q;

// 	float s;
// 	float tq[4];
// 	int    i, j;

// 	// Use tq to store the largest trace
// 	tq[0] = 1 + mat.M[0][0] + mat.M[1][1] + mat.M[2][2];
// 	tq[1] = 1 + mat.M[0][0] - mat.M[1][1] - mat.M[2][2];
// 	tq[2] = 1 - mat.M[0][0] + mat.M[1][1] - mat.M[2][2];
// 	tq[3] = 1 - mat.M[0][0] - mat.M[1][1] + mat.M[2][2];

// 	// Find the maximum (could also use stacked if's later)
// 	j = 0;
// 	for (i = 1; i < 4; i++) j = (tq[i] > tq[j]) ? i : j;

// 	// check the diagonal
// 	if (j == 0)
// 	{
// 		/* perform instant calculation */
// 		q.W = tq[0];
// 		q.X = mat.M[1][2] - mat.M[2][1];
// 		q.Y = mat.M[2][0] - mat.M[0][2];
// 		q.Z = mat.M[0][1] - mat.M[1][0];
// 	}
// 	else if (j == 1)
// 	{
// 		q.W = mat.M[1][2] - mat.M[2][1];
// 		q.X = tq[1];
// 		q.Y = mat.M[0][1] + mat.M[1][0];
// 		q.Z = mat.M[2][0] + mat.M[0][2];
// 	}
// 	else if (j == 2)
// 	{
// 		q.W = mat.M[2][0] - mat.M[0][2];
// 		q.X = mat.M[0][1] + mat.M[1][0];
// 		q.Y = tq[2];
// 		q.Z = mat.M[1][2] + mat.M[2][1];
// 	}
// 	else /* if (j==3) */
// 	{
// 		q.W = mat.M[0][1] - mat.M[1][0];
// 		q.X = mat.M[2][0] + mat.M[0][2];
// 		q.Y = mat.M[1][2] + mat.M[2][1];
// 		q.Z = tq[3];
// 	}

// 	s = sqrt(0.25 / tq[j]);
// 	q.W *= s;
// 	q.X *= s;
// 	q.Y *= s;
// 	q.Z *= s;

// 	return q;
// }

// FMatrix makeLookat(const FVector& EyePosition, const FVector& LookAtPosition, const FVector& UpVector)
// {
// 	FMatrix mat;

// 	const FVector ZAxis = (LookAtPosition - EyePosition).GetSafeNormal();
// 	const FVector XAxis = (UpVector ^ ZAxis).GetSafeNormal();
// 	const FVector YAxis = ZAxis ^ XAxis;
// 	mat.M[0][0] = -XAxis[0];
// 	mat.M[0][1] = YAxis[0];
// 	mat.M[0][2] = -ZAxis[0];
// 	mat.M[0][3] = 0.0;

// 	mat.M[1][0] = -XAxis[1];
// 	mat.M[1][1] = YAxis[1];
// 	mat.M[1][2] = -ZAxis[1];
// 	mat.M[1][3] = 0.0;

// 	mat.M[2][0] = -XAxis[2];
// 	mat.M[2][1] = YAxis[2];
// 	mat.M[2][2] = -ZAxis[2];
// 	mat.M[2][3] = 0.0;


// 	mat.M[3][0] = 0;
// 	mat.M[3][1] = 0;
// 	mat.M[3][2] = 0;
// 	mat.M[3][3] = 1;

// 	return mat;
// }
// float UQiumuJZ::GetMyFov()
// {
// 	float left = -1 * tanf(vFov[0]);
// 	float right = 1 * tanf(vFov[1]);
// 	float top = 1 * tanf(vFov[2]);
// 	float bottom = -1 * tanf(vFov[3]);
// 	wh = right / top;
// 	float m_Fov = (atan(right) - atan(left)) * 180 / PI;

// 	return m_Fov;
// }

// FRotator UQiumuJZ::GetRotation()
// {
// 	FRotator rotator;
// 	FILE* file;
// 	int nBufSize = -1;



// 		FMatrix CameraMat = makeLookat(FVector(0, 0, 0), FVector(LookAt[0], LookAt[1], -LookAt[2]), FVector(Up[0], Up[1], -Up[2]));

// 		g_CameraMat = CameraMat;
// 		FQuat quat = getRotate(CameraMat);
// 		Quaternion qquat(quat.X, quat.Y, quat.Z, quat.W);
// 		double HPR[3];
// 		quaternion2Euler(qquat, HPR, zxy);
// 		rotator = FRotator(-HPR[1] * 180 / PI, HPR[0] * 180 / PI, HPR[2] * 180 / PI);

// 	g_rotator = rotator;
// 	return rotator;
// }

// void UQiumuJZ::CreateMask(UObject* Outer, UTextureRenderTarget2D* RenderTex, int32 channel)
// {
// 	FString gameDir = FPlatformProcess::BaseDir();   //??ȡexe????·??
// 	FString path = gameDir + "adjustdata/";			//?ļ?·??
// 	FString IniValve;

// 	int nx = g_width;
// 	int ny = g_height;
	
// 	IniValve = FString::FromInt(UConfigReader::getUConfigReaderTarget()->getChannelID());
// 	FString strings;
// 	FTextureRenderTarget2DResource* gridTexResource = (FTextureRenderTarget2DResource*)RenderTex->Resource;
// 	RenderTex->Filter = TF_Nearest;
// 	FCanvas* gridCanvas = new FCanvas(gridTexResource, NULL, 0, 0, 0, GMaxRHIFeatureLevel);
// 	FILE* file;
// 	int nBufSize = -1;
// 	string AdjustDataFile(TCHAR_TO_UTF8(*(path + "mask_" + IniValve + ".dat")));

// 	if (fopen_s(&file, AdjustDataFile.c_str(), "rb") == NULL)
// 	{
// 		float** points;
// 		points = new float* [ny];
// 		for (int i = 0; i < ny; i++)
// 		{
// 			points[i] = new float[nx];
// 		}
// 		nBufSize = nx * ny * sizeof(float);
// 		char* pBuf = new char[nBufSize];
// 		char* pBufPtr = pBuf;

// 		fread(pBuf, sizeof(char), nBufSize, file);

// 		int nCount = 0;
// 		for (int i = 0; i < ny; i++)
// 		{
// 			for (int j = 0; j < nx; j++)
// 			{
// 				memcpy(&points[i][j], pBufPtr, sizeof(float));
// 				pBufPtr += sizeof(float);
// 				if (points[i][j] < 0.0 && points[i][j] > 1.0)
// 				{
// 					points[i][j] = 0.0;
// 				}

// 				FCanvasLineItem line(FVector2D(j, i), FVector2D(j, i));
// 				line.LineThickness = 1;
// 				line.SetColor(FLinearColor(points[i][j], 0.0, 0.0));
// 				line.BlendMode = SE_BLEND_Opaque;
// 				gridCanvas->DrawItem(line);
// 			}
// 		}
// 		delete[]points;
// 		points = NULL;
// 	}
// 	gridCanvas->Flush_GameThread();
// 	RenderTex->UpdateResourceImmediate(false);
// }

// void UQiumuJZ::CreateInf(UObject* Outer, UTextureRenderTarget2D* RenderTex, int32 channel)
// {
// 	FString gameDir = FPlatformProcess::BaseDir();   //??ȡexe????·??
// 	FString path = gameDir + "adjustdata/";			//?ļ?·??
// 	FString IniValve;
// 	IniValve = FString::FromInt(UConfigReader::getUConfigReaderTarget()->getChannelID());
// 	FString strings;
// 	FTextureRenderTarget2DResource* gridTexResource = (FTextureRenderTarget2DResource*)RenderTex->Resource;
// 	RenderTex->Filter = TF_Nearest;
// 	FCanvas* gridCanvas = new FCanvas(gridTexResource, NULL, 0, 0, 0, GMaxRHIFeatureLevel);
// 	FILE* file;
// 	int nBufSize = -1;
// 	string AdjustDataFile(TCHAR_TO_UTF8(*(path + "itf_itfInv_" + IniValve + ".dat")));

// 	if (fopen_s(&file, AdjustDataFile.c_str(), "rb") == NULL)
// 	{
// 		nBufSize = 3 * 1024 * sizeof(float) * 2;
// 		char* pBuf = new char[nBufSize];
// 		char* pBufPtr = pBuf;
// 		fread(pBuf, sizeof(char), nBufSize, file);

// 		color* itfPoints = new color[1024];
// 		int nCount = 0;
// 		for (int i = 0; i < 1024; i++)
// 		{
// 			memcpy(&itfPoints[i], pBufPtr, sizeof(color));
// 			pBufPtr += sizeof(color);
// 			for (int j = 0; j < 1024; j++)
// 			{
// 				FCanvasLineItem line(FVector2D(j, i), FVector2D(j, i));
// 				line.LineThickness = 1;
// 				line.SetColor(FLinearColor(itfPoints[i].r, itfPoints[i].g, itfPoints[i].b));
// 				line.BlendMode = SE_BLEND_Opaque;
// 				gridCanvas->DrawItem(line);
// 			}
// 		}
// 		delete[]itfPoints;
// 		itfPoints = NULL;
// 	}
// 	gridCanvas->Flush_GameThread();
// 	RenderTex->UpdateResourceImmediate(false);
// }

// void UQiumuJZ::CreateInfInv(UObject* Outer, UTextureRenderTarget2D* RenderTex, int32 channel)
// {
// 	FString gameDir = FPlatformProcess::BaseDir();   //??ȡexe????·??
// 	FString path = gameDir + "adjustdata/";			//?ļ?·??
// 	FString IniValve;
// 	UE_Tool::Instance()->ReSet();
// 	IniValve = FString::FromInt(UConfigReader::getUConfigReaderTarget()->getChannelID());
// 	FString strings;
// 	FTextureRenderTarget2DResource* gridTexResource = (FTextureRenderTarget2DResource*)RenderTex->Resource;
// 	RenderTex->Filter = TF_Nearest;
// 	FCanvas* gridCanvas = new FCanvas(gridTexResource, NULL, 0, 0, 0, GMaxRHIFeatureLevel);
// 	FILE* file;
// 	int nBufSize = -1;
// 	string AdjustDataFile(TCHAR_TO_UTF8(*(path + "itf_itfInv_" + IniValve + ".dat")));

// 	if (fopen_s(&file, AdjustDataFile.c_str(), "rb") == NULL)
// 	{
// 		nBufSize = 3 * 1024 * sizeof(float) * 2;
// 		char* pBuf = new char[nBufSize];
// 		char* pBufPtr = pBuf;
// 		fread(pBuf, sizeof(char), nBufSize, file);

// 		color* itfInvPoints = new color[1024];

// 		color* mo = new color();

// 		int nCount = 0;

// 		pBufPtr += 1024 * sizeof(color);

// 		for (int i = 0; i < 1024; i++)
// 		{
// 			memcpy(&itfInvPoints[i], pBufPtr, sizeof(color));
// 			pBufPtr += sizeof(color);
// 			for (int j = 0; j < 1024; j++)
// 			{
// 				FCanvasLineItem line(FVector2D(j, i), FVector2D(j, i));
// 				line.LineThickness = 1;
// 				line.SetColor(FLinearColor(itfInvPoints[i].r, itfInvPoints[i].g, itfInvPoints[i].b));
// 				line.BlendMode = SE_BLEND_Opaque;
// 				gridCanvas->DrawItem(line);
// 			}
// 		}
// 		delete[]itfInvPoints;
// 		itfInvPoints = NULL;
// 		delete mo;
// 		mo = NULL;
// 	}
// 	gridCanvas->Flush_GameThread();
// 	RenderTex->UpdateResourceImmediate(false);
// }

// FRotator UQiumuJZ::GetRotation()
// {
// 	FRotator rotator;
// 	FILE* file;
// 	int nBufSize = -1;

// 	FString gameDir = FPlatformProcess::BaseDir();   //??ȡexe????·??
// 	UE_LOG(LogTemp, Log, TEXT("BaseDir: %s"), *gameDir);
// 	UE_LOG(LogTemp, Log, TEXT("ChannelID: %d"), UConfigReader::getUConfigReaderTarget()->getChannelID());
// 	FString path = gameDir + "adjustdata/";			//?ļ?·??
// 	FString IniValve = "0";
// 	IniValve = FString::FromInt(UConfigReader::getUConfigReaderTarget()->getChannelID());
// 	IniValve = IniValve + ".dat";
// 	std::string CameraDataFile(TCHAR_TO_UTF8(*(path + IniValve)));

// 	FRotator quatAdjust;
// 	if (fopen_s(&file, CameraDataFile.c_str(), "rb") == NULL)
// 	{
// 		int len = 0;
// 		FVector LookAt = FVector(0.0, 0.0, 0.0);

// 		for (int i = 0; i < 3; i++)
// 		{
// 			fread(&LookAt[i], sizeof(LookAt[i]), 1, file);
// 			len += sizeof(LookAt[i]);
// 		}

// 		FVector  Up = FVector(0.0, 0.0, 0.0);
// 		for (int i = 0; i < 3; i++)
// 		{
// 			fread(&Up[i], sizeof(Up[i]), 1, file);
// 			len += sizeof(Up[i]);
// 		}

// 		for (int i = 0; i < 4; i++)
// 		{
// 			fread(&vFov[i], sizeof(vFov[i]), 1, file);
// 			len += sizeof(vFov[i]);
// 		}
// 		FMatrix CameraMat = makeLookat(FVector(0, 0, 0), FVector(LookAt[0], LookAt[1], -LookAt[2]), FVector(Up[0], Up[1], -Up[2]));

// 		g_CameraMat = CameraMat;
// 		FQuat quat = getRotate(CameraMat);
// 		Quaternion qquat(quat.X, quat.Y, quat.Z, quat.W);
// 		double HPR[3];
// 		quaternion2Euler(qquat, HPR, zxy);
// 		rotator = FRotator(-HPR[1] * 180 / PI, HPR[0] * 180 / PI, HPR[2] * 180 / PI);
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("File does not exist!"));
// 		rotator = FRotator(0.0, 0.0, 0.0);
// 	}

// 	g_rotator = rotator;
// 	return rotator;
// }

// float UQiumuJZ::GetMyFov()
// {
// 	float left = -1 * tanf(vFov[0]);
// 	float right = 1 * tanf(vFov[1]);
// 	float top = 1 * tanf(vFov[2]);
// 	float bottom = -1 * tanf(vFov[3]);
// 	wh = right / top;
// 	float m_Fov = (atan(right) - atan(left)) * 180 / PI;

// 	return m_Fov;
// }