size_t partition_j_modified(vector<unsigned>& a, size_t lo, size_t hi)
{
  if (lo < hi && hi < a.size())
  {
    unsigned pivot = a.at(lo);
    size_t position = lo;
    unsigned duplicate_count = 0;
    for (size_t index = lo + 1; index <= hi; index++)
    {
      if (a.at(index) < pivot)
      {
        position++;
        swap(a.at(position), a.at(index));
      }
      else if(a.at(index) == pivot)
      {
        duplicate_count++;
        position++;
        swap(a.at(position), a.at(index));
        swap(a.at(lo + duplicate_count), a.at(position));
      }
    }
    for (size_t count = 0; count <= duplicate_count; count++)
    {
      swap(a.at(lo + count), a.at(position - count));
    }
    return position;
  }
  return lo;
}