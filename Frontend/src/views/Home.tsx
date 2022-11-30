import { SearchOutlined, VerticalLeftOutlined } from '@ant-design/icons';
import { Image, Layout, Col, Typography, Row, Button, Card, Divider } from 'antd';
import walp from "../assets/images/walp.jpg"
import _Navbar from '../components/Navbar';

const { Content } = Layout;
const { Title, Paragraph } = Typography;

function Home(): any {
  return (
    <>
      <Layout className='root-content'>
      <_Navbar />
        <Content className='items'>
          <Row>
            
            <Card className='box'>
              <Row>
                <Col span={12}>
                  <Image src={walp} preview={false} />
                </Col>
                <Col span={12}>
                  <Title level={4}>
                    Monster
                  </Title>
                  <Paragraph className='content'>
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam euismod egestas faucibus. Maecenas lacinia enim vel risus pellentesque, ut ullamcorper odio vestibulum. Vestibulum quis gravida sapien. Curabitur sollicitudin pharetra risus, vitae placerat elit posuere eu. Cras nec velit felis...
                  </Paragraph>
        
                  <Paragraph className='date'>
                    3 ago
                  </Paragraph>
                  <Col className='icon-act'>
                    <VerticalLeftOutlined />
                  </Col>
                </Col>
              </Row>
            </Card>

            <Card className='box'>
              <Row>
                <Col span={12}>
                  <Image src={walp} preview={false} />
                </Col>
                <Col span={12}>
                  <Title level={4}>
                    Monster
                  </Title>
                  <Paragraph className='content'>
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam euismod egestas faucibus. Maecenas lacinia enim vel risus pellentesque, ut ullamcorper odio vestibulum. Vestibulum quis gravida sapien. Curabitur sollicitudin pharetra risus, vitae placerat elit posuere eu. Cras nec velit felis...
                  </Paragraph>
        
                  <Paragraph className='date'>
                    3 ago
                  </Paragraph>
                  <Col className='icon-act'>
                    <VerticalLeftOutlined />
                  </Col>
                </Col>
              </Row>
            </Card>
          
          </Row>

          <Divider />
          <Row className='list-items'>

          <Card className='box'>
              <Row>
                <Col span={8}>
                  <Image src={walp} preview={false} />
                </Col>
                <Col span={16}>
                  <Title level={4}>
                    Monster
                  </Title>
                  <Paragraph className='content'>
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam euismod egestas faucibus. Maecenas lacinia enim vel risus pellentesque, ut ullamcorper odio vestibulum. Vestibulum quis gravida sapien. Curabitur sollicitudin pharetra risus, vitae placerat elit posuere eu. Cras nec velit felis...
                  </Paragraph>
        
                  <Paragraph className='date'>
                    3 ago
                  </Paragraph>
                  <Col className='icon-act'>
                    <VerticalLeftOutlined />
                  </Col>
                </Col>
              </Row>
            </Card>

          </Row>
        </Content>
      </Layout>
    </>
  );
};

export default Home;
