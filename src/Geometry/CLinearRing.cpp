//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : PSDE
//  @ File Name : CLinearRing.cpp
//  @ Date : 2010/12/20
//  @ Author : 
//
//


#include "CLinearRing.h"

namespace Geometry {
CLinearRing::CLinearRing() {
	mCoord = new CCoVecSequence();
}

CLinearRing::CLinearRing(const CLinearRing & ln) :
	CLineString(ln) {
	validate();
}

CLinearRing::CLinearRing(const CCoVecSequence & seq) :
	CLineString(seq) {
	validate();
}

CLinearRing::~CLinearRing() {

}

CGeometry* CLinearRing::clone() const {
	return new CLinearRing(*this);
}

void CLinearRing::validate() {
	if (mCoord->getSize() == 0)
		return;
	if (mCoord->getSize() < 4) {
		throw CIlligalGeomException("A LinearString must at least have 4 coordinates");
		return;
	}
	if (!isClosed()) {
		throw CIlligalGeomException("A LinearString must be a closed LineString");
		return;
	}
}

string CLinearRing::getGeometryType() const {
	return "CLinearRing";
}
COpenGISType::OPENGIS_TYPE CLinearRing::getOGISType() const {
	return COpenGISType::OGIS_LINEARRING;
}
}
