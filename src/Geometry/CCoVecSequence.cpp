//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : PSDE
//  @ File Name : CCoVecSequence.cpp
//  @ Date : 2010/12/20
//  @ Author : 
//
//


#include "CCoVecSequence.h"
#include "CCoordinate.h"
#include "CRectangle.h"

namespace Geometry {
CCoVecSequence::CCoVecSequence() :
	mBoundingRect() {
	mVect = new vector<CCoordinate> ();
	mDirtyBoundingRect = false;
}
CCoVecSequence::CCoVecSequence(size_t n) {
	mVect = new vector<CCoordinate> (n);
	mDirtyBoundingRect = true;
}
CCoVecSequence::CCoVecSequence(const CCoordinate &c) {
	mVect = new vector<CCoordinate> (1);
	setAt(0, c);
	mDirtyBoundingRect = true;
}
CCoVecSequence::CCoVecSequence(const CCoVecSequence & seq) {
	mVect = new vector<CCoordinate> (*seq.mVect);
	mDirtyBoundingRect = seq.mDirtyBoundingRect;
	mBoundingRect = seq.mBoundingRect;
}

CCoVecSequence::~CCoVecSequence() {
	delete mVect;
}

CCoVecSequence *CCoVecSequence::clone() const {
	return new CCoVecSequence(*this);
}

CRectangle CCoVecSequence::getBoundingRect() const {
	if (mVect->size() == 0)
		return CRectangle();
	if (!mDirtyBoundingRect)
		return mBoundingRect;
	double minx = (*mVect)[0].x, miny = (*mVect)[0].y;
	double maxx = (*mVect)[0].x, maxy = (*mVect)[0].y;
	for (size_t i = 1; i < mVect->size(); i++) {
		minx = min(minx, (*mVect)[i].x);
		miny = min(miny, (*mVect)[i].y);
		maxx = max(maxx, (*mVect)[i].x);
		maxy = max(maxy, (*mVect)[i].y);
	}
	return CRectangle(minx, miny, maxx, maxy);
}
bool CCoVecSequence::isEmpty() const {
	return mVect->empty();
}

void CCoVecSequence::add(const CCoordinate & pt) {
	mDirtyBoundingRect = true;
	mVect->push_back(pt);
}
void CCoVecSequence::add(const double x, const double y, const double z) {
	mDirtyBoundingRect = true;
	add(CCoordinate(x, y, z));
}
void CCoVecSequence::add(const CCoVecSequence & seq) {
	// to be done
}
void CCoVecSequence::pop() {
	mDirtyBoundingRect = true;
	mVect->pop_back();
}

CCoordinate CCoVecSequence::getAt(size_t pos) const {
	return (*mVect)[pos];
}

void CCoVecSequence::clear() {
	mDirtyBoundingRect = true;
	mVect->clear();
}

void CCoVecSequence::removeAt(size_t pos) {
	mDirtyBoundingRect = true;
	mVect->erase(mVect->begin() + pos);
}

void CCoVecSequence::insertAt(size_t pos, CCoordinate &c) {
	mVect->insert(mVect->begin() + pos, c);
}

void CCoVecSequence::setAt(size_t pos, const CCoordinate & c) {
	mDirtyBoundingRect = true;
	(*mVect)[pos] = c;
}

size_t CCoVecSequence::getSize() const {
	return mVect->size();
}

CCoordinate CCoVecSequence::first() {
	return *(mVect->begin());
}

CCoordinate CCoVecSequence::back() {
	return *(--mVect->end());
}

void CCoVecSequence::reverse() {
	if (!mVect->empty())
		std::reverse(mVect->begin(), mVect->end());
}

CCoVecSequence & CCoVecSequence::unique() {
	vector<CCoordinate>::iterator tend = std::unique(mVect->begin(), mVect->end());
	mVect->erase(tend, mVect->end());
	return *this;
}

bool CCoVecSequence::equal(const CCoVecSequence &a, const CCoVecSequence &b) {
	if (a.getSize() != b.getSize())
		return false;
	size_t mx = max(a.getSize(), b.getSize());
	for (size_t i = 0; i < mx; i++) {
		if (a.getAt(i) != b.getAt(i))
			return false;
	}
	return true;
}
bool CCoVecSequence::equal(const CCoVecSequence &a, const CCoVecSequence &b, double eps) {
	if (a.getSize() != b.getSize())
		return false;
	size_t mx = max(a.getSize(), b.getSize());
	for (size_t i = 0; i < mx; i++) {
		if (CCoordinate::equalCCoordinate(a.getAt(i), b.getAt(i), eps))
			return false;
	}
	return true;
}

CCoordinate& CCoVecSequence::operator[](size_t pos) const {
	return (*mVect)[pos];
}

std::ostream& operator<<(std::ostream& out, const CCoVecSequence& seq) {

	for (size_t i = 0, n = seq.getSize(); i < n; i++) {
		out << seq[i];
	}
	return out;
}

}
