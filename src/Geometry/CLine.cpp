//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : PSDE
//  @ File Name : CLine.cpp
//  @ Date : 2010/12/20
//  @ Author : 
//
//


#include "CLine.h"

namespace Geometry {

CLine::CLine() {
	mCoord = new CCoVecSequence();
}
CLine::CLine(const CLine & ln) :
	CLineString(ln) {
	validateConstruction();
}

CLine::CLine(const CCoVecSequence & seq) :
	CLineString(seq) {
	// something should be done
	validateConstruction();

}

CLine::CLine(const CCoordinate &c1, const CCoordinate &c2) {
	mCoord = new CCoVecSequence();
	mCoord->add(c1);
	mCoord->add(c2);
}
CGeometry* CLine::clone() const {
	return new CLine(*this);
}

double CLine::getArea() const {
	return 0.00;
}

double CLine::getLength() const {
	// to be done
	return 0.00;
}
void CLine::validateConstruction() {
	// to be done
}
size_t CLine::getNumPoints() {
	if (!isEmpty())
		return mCoord->getSize();
	return 0;
}

bool CLine::equalExact(CGeometry* geom, double eps) const {
	if (!isEquivalentClass(geom))
		return false;
	return CLineString::equalExact(geom, eps);
}


string CLine::getGeometryType() const {
	return "CLine";
}
COpenGISType::OPENGIS_TYPE CLine::getOGISType()const {
	return COpenGISType::OGIS_LINE;
}
bool CLine::isEmpty() const {
	// to be done
	return true;
}

}