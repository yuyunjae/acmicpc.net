import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    # world.info()
    df = world[(world['area'] >= 3000000) | (world['population'] >= 25000000)]
    return df[['name', 'population', 'area']]
    # world DataFrame에서 area값이 3000000이상이거나, population이 25000000이상인 row에 대해
    # name, population, area 열 값들을 가져와라.
