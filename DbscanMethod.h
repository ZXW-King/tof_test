#pragma once
#ifndef DBSCAN_METHOD_H
#define DBSCAN_METHOD_H

#include <iostream>
#include <math.h>
#include <vector>

static int S_temp = 0;

enum  POINT_TYPE
{
	POINT_DEFAULT,		// δ����
	POINT_CORE,			// ���Ķ���
	POINT_BOUNDARY,		// �߽����
	POINT_NOISE			// ����
};
enum POINT_STATE
{
	VISIT_NO,			// δ������
	VISIT_YES			// �ѱ�����
};						
						
/*
DbscanPoint��ʼ����Ҫ����һ��std::vector<double>���͵�����
���￼�ǵ�Point����������һ����ά�ĵ㣬����������ά��
һ��������ά�ȵ����갴��һ��˳������std::vector<double>��
*/
class DbscanPoint
{
public:
	DbscanPoint() = default;
	DbscanPoint(std::vector<double> xn) :xn(xn) { }

public:
	std::vector<double> xn;//���꣨�������ڶ�ά��
	int cluster = 0;//�ڼ�����
	int num_pts = 1;//��¼�������ж��ٸ��㣨�����Լ������Գ�ʼֵΪ1��
	int point_type = POINT_DEFAULT;
	int  visited = VISIT_NO;//���Ƿ񱻱���
	std::vector<DbscanPoint*> vec_dbscan_point_ptr;//���ڴ�������ڵĵ�
};


double CalculateDistance(DbscanPoint* point1, DbscanPoint* point2);
void Dbscan(DbscanPoint* dbscan_point_ptr, int cluster_current);

/*
������
vec_dbscan_point	��Ҫ����һ��DbscanPoint���͵�vector�����vector�������DbscanPointӦ�����Ѿ���ʼ�����������
Eps					����������ķ�ΧEps
MinPts				������������MinPts���㣨�����Լ������ܽ������ĵ�
*/
void DbscanMethod(std::vector<DbscanPoint>& vec_dbscan_point, double Eps, int MinPts);

#endif