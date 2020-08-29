
void updateSegmentTree(int si, int ss, int upi)
{
	// cout<<"\nsi: "<<si<<" ss: "<<ss<<" se: "<<se;
	if(ss == se)
	{
		segmentTree[si] = arr[ss];
		return;
	}

	int mid = ss + (se - ss)/2;
	if(qi <= upi)
		updateSegmentTree(2*si, ss, mid, upi);
	else
		updateSegmentTree((2*si)+1, mid+1, se, upi);

	segmentTree[si] = min(segmentTree[2*si], segmentTree[(2*si)+1]);
}